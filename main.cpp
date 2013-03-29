/*
 * main.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

// TODO Clean-up code

#include "inc.h"

bool keySpecialStates[246];
bool keyStates[255];
void fsmFunction(void);

b2Vec2 gravity(0.0f,-9.7e-1f);
bool doSleep = true;
b2World *world = new b2World(gravity);
b2Body *MainAgent;
GameData gameData;
MainScreen *mainScreen;
Menu *mainMenu;
Stage *testStage;
DebugDraw drawclass;

float32 timeStep = 1/10.0;      //the length of time passed to simulate (seconds)
int32 velocityIterations = 6;   //how strongly to correct velocity
int32 positionIterations = 3;   //how strongly to correct position

gameScreenEnum gameScreen = Start_Screen;

int phaserChannel = -1;

GLuint texture[10];

int main(int argc, char** argv) {

	// Init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200,800);
	glutInitWindowSize(MAIN_WINDOW_WIDTH,MAIN_WINDOW_HEIGHT);
	int intMainWindowID;
	intMainWindowID = glutCreateWindow("Super Bira World");



	// Loading Texture

	//FILE *t = fopen("biraface.png","rb");
	//if(t) printf("Abriu\n");
	/* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
		(
			"../img/biraface.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);

	/* check for an error during the load process */
	/*if( 0 == texture[0] )
	{
		printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
	}*/


	    // Typical Texture Generation Using Data From The Bitmap
	    glBindTexture(GL_TEXTURE_2D, texture[0]);
	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


	    // Handler Functions
	    	initializeKeySpecialStates();
	    	initializeKeyStates();
	    	glutKeyboardFunc(keyboardHandler);
	    	glutKeyboardUpFunc(keyboardUpHandler);
	    	glutSpecialFunc(specialKeysHandler);
	    	glutSpecialUpFunc(specialKeysUpHandler);

	    	// Sound Functions
	    	prepareSoundDevice();

	    	// Initializing Game Data
	    	gameData = GameData();

	// Rendering
	initScreen();
	glutDisplayFunc(fsmFunction);
	glutMainLoop();

	return 0;
}

void fsmFunction(void) {

	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	// State Machine to control Screens
	// todo complete all the states
	switch(gameScreen) {


		// Initial Screen
		case Start_Screen:
			// Initializations
			if(!mainMenu) {
				mainMenu = new Menu;
				mainMenu->addMenuItem("New Game",NOT_SUB_LIST);
				mainMenu->addMenuItem("Load Game",NOT_SUB_LIST);
				mainMenu->addMenuItem("Settings",NOT_SUB_LIST);
				//mainMenu->;
			}
			if(!mainScreen) mainScreen =  new MainScreen(mainMenu);
			// Transition Function
			if(keyStates[13] == true) {
				printf("Transitioning to Stage\n");
				keyStates[13] = false;
				gameScreen = Stage_Screen;
			}


			// Actions on this stage
			gameData.changeGameScreen(mainScreen);
			break;

		// Stage_Selection Screen
		case Stage_Selection_Screen:
			if(keyStates[13] == true) {
				printf("Transitioning to Start_Screen\n");
				keyStates[13] = false;
				gameScreen = Start_Screen;

			}
			glClear (GL_COLOR_BUFFER_BIT);
			glClearColor(1,1,1,0);
			break;

		// Stage Screen
		case Stage_Screen:
			if(!testStage) testStage = new Stage("../maps/test.map","../enemy/enemytest.ene");
			gameData.changeGameScreen(testStage);
			break;
	};

	// Render
	gameData.currentScreen->render();

	// Looping
	glutPostRedisplay();
	glutSwapBuffers();

}
/*
GLuint loadTexture(const string filename, int &width, int &height)
 {
   //header for testing if it is a png
   png_byte header[8];

   //open file as binary
   FILE *fp = fopen(filename.c_str(), "rb");
   if (!fp) {
     return TEXTURE_LOAD_ERROR;
   }

   //read the header
   fread(header, 1, 8, fp);

   //test if png
   int is_png = !png_sig_cmp(header, 0, 8);
   if (!is_png) {
     fclose(fp);
     return TEXTURE_LOAD_ERROR;
   }

   //create png struct
   png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL,
       NULL, NULL);
   if (!png_ptr) {
     fclose(fp);
     return (TEXTURE_LOAD_ERROR);
   }

   //create png info struct
   png_infop info_ptr = png_create_info_struct(png_ptr);
   if (!info_ptr) {
     png_destroy_read_struct(&png_ptr, (png_infopp) NULL, (png_infopp) NULL);
     fclose(fp);
     return (TEXTURE_LOAD_ERROR);
   }

   //create png info struct
   png_infop end_info = png_create_info_struct(png_ptr);
   if (!end_info) {
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
     fclose(fp);
     return (TEXTURE_LOAD_ERROR);
   }

   //png error stuff, not sure libpng man suggests this.
   if (setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
     fclose(fp);
     return (TEXTURE_LOAD_ERROR);
   }

   //init png reading
   png_init_io(png_ptr, fp);

   //let libpng know you already read the first 8 bytes
   png_set_sig_bytes(png_ptr, 8);

   // read all the info up to the image data
   png_read_info(png_ptr, info_ptr);

   //variables to pass to get info
   int bit_depth, color_type;
   png_uint_32 twidth, theight;

   // get info about png
   png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type,
       NULL, NULL, NULL);

   //update width and height based on png info
   width = twidth;
   height = theight;

   // Update the png info struct.
   png_read_update_info(png_ptr, info_ptr);

   // Row size in bytes.
   int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

   // Allocate the image_data as a big block, to be given to opengl
   png_byte *image_data = new png_byte[rowbytes * height];
   if (!image_data) {
     //clean up memory and close stuff
     png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
     fclose(fp);
     return TEXTURE_LOAD_ERROR;
   }

   //row_pointers is for pointing to image_data for reading the png with libpng
   png_bytep *row_pointers = new png_bytep[height];
   if (!row_pointers) {
     //clean up memory and close stuff
     png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
     delete[] image_data;
     fclose(fp);
     return TEXTURE_LOAD_ERROR;
   }
   // set the individual row_pointers to point at the correct offsets of image_data
   for (int i = 0; i < height; ++i)
     row_pointers[height - 1 - i] = image_data + i * rowbytes;

   //read the png into image_data through row_pointers
   png_read_image(png_ptr, row_pointers);

   //Now generate the OpenGL texture object
   GLuint texture;
   glGenTextures(1, &texture);
   glBindTexture(GL_TEXTURE_2D, texture);
   glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA, width, height, 0,
       GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*) image_data);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   //clean up memory and close stuff
   png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
   delete[] image_data;
   delete[] row_pointers;
   fclose(fp);

   return texture;
 }
*/
