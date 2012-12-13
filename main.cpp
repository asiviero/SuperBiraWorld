/*
 * main.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "inc.h"

#include <pthread.h>
bool keySpecialStates[246];
bool keyStates[255];
void fsmFunction(void);

b2Vec2 gravity(0.0f,-9.7f);
bool doSleep = true;

b2World *world = new b2World(gravity);
b2BodyDef groundBodyDef,MainAgentDef,enemyDef;
b2Body *MainAgent, *enemyTest;
b2PolygonShape groundBox,MainAgentShape,enemyShape;
b2FixtureDef MainAgentFixtureDef,enemyFixtureDef;
b2Fixture *MainAgentFixture,*enemyFixture;


float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
int32 velocityIterations = 6;   //how strongly to correct velocity
int32 positionIterations = 3;   //how strongly to correct position

gameScreenEnum gameScreen = Start_Screen;

void display(void);
void loadTerrain(ifstream &map,b2World *world);

//Mix_Chunk *phaser = NULL;
int phaserChannel = -1;
/*int main() {
	//printf("ok");
	return 1;
}
*/


int main(int argc, char** argv) {

	//printf("ok");
	// Init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200,800);
	glutInitWindowSize(MAIN_WINDOW_WIDTH,MAIN_WINDOW_HEIGHT);
	int intMainWindowID;
	intMainWindowID = glutCreateWindow("Super Bira World");

	// Handler Functions
	initializeKeySpecialStates();
	initializeKeyStates();
	glutKeyboardFunc(keyboardHandler);
	glutKeyboardUpFunc(keyboardUpHandler);
	glutSpecialFunc(specialKeysHandler);
	glutSpecialUpFunc(specialKeysUpHandler);




	// box2d functions
/*

	m_move *moveTest = new m_move(MAIN_AGENT);

	agentData *biraData;
	biraData = new agentData(MAIN_AGENT,(void*)moveTest);
	// Creating the body
	MainAgentDef.position.Set(X_AXIS_SIZE/2,Y_AXIS_SIZE/2);
	MainAgentDef.type = b2_dynamicBody;

	MainAgent = world->CreateBody(&MainAgentDef);
	MainAgent->SetUserData(biraData);

	// Creates a box, which is to be featured in the agent body
	MainAgentShape.SetAsBox(4,4);
	MainAgentFixtureDef.friction = 0.1;
	MainAgentFixtureDef.density = 0.1;
	MainAgentFixtureDef.restitution = 0;
	MainAgentFixtureDef.shape = &MainAgentShape;

	//polyTest1.SetAsBox(X_AXIS_SIZE/10,Y_AXIS_SIZE/10);

	// Applies it
	MainAgent->CreateFixture(&MainAgentFixtureDef);
	MainAgent->ResetMassData();


	// Sets the class used for debug drawing. It came from Box2d testbed
	DebugDraw drawclass = DebugDraw();
	drawclass.SetFlags(1);
	world->SetDebugDraw(&drawclass);

	superBiraWorldContactListener *listener = new superBiraWorldContactListener();
	world->SetContactListener(listener);


	// Terrain loading
	char terrainFile[] = "../maps/test.map";
	ifstream terrainMap(terrainFile);
	//cout << "passei!\n";
	if(terrainMap.is_open()) {
		//cout << "map file loaded succesfully, passing it on to function\n";
		loadTerrain(terrainMap,world);
	}
	terrainMap.close();
	//cout << "passei!\n";

	// Enemy loading
	char enemyFile[] = "../enemy/enemytest.ene";
	ifstream enemyFileStream(enemyFile);
	//cout << "passei!\n";
	if(enemyFileStream.is_open()) {
		//cout << "map file loaded succesfully, passing it on to function\n";
		loadEnemies(enemyFileStream,world);
	}
	enemyFileStream.close();
	//cout << "passei!\n";


	// Sound Functions
	prepareSoundDevice();
	playBackgroundMusic("../UbirajaraAparecendo.mp3");
	//phaser = Mix_LoadWAV("../phaser.wav");




	// Testing Shuffle
	/*int randomteste[10];
	for(int i=0;i<10;i++) randomteste[i] = [i];
	random_*/

//printf("ok");
	// Rendering
	initScreen();

	//glutDisplayFunc(display);
	glutDisplayFunc(fsmFunction);
	char lixo;
		//scanf("%c",&lixo);
	glutMainLoop();

	return 0;
}

int t=0;
void display(void)
{
/*  clear all pixels  */
/*
		glClear (GL_COLOR_BUFFER_BIT);
		glPushMatrix();

		// Simulator functions begin here
		drawGrid();

		// Draws every object in the world

		world->DrawDebugData();

		// Simulator functions end here

		glPopMatrix();

		world->Step(timeStep, velocityIterations, positionIterations);

		glutPostRedisplay();
		glutSwapBuffers();*/

		//cout << "Directionals:\nUp: " << keySpecialStates[GLUT_KEY_UP] << "\nDown: " << keySpecialStates[GLUT_KEY_DOWN]
		  //       << "\nLeft: " << keySpecialStates[GLUT_KEY_LEFT] << "\nRight: " << keySpecialStates[GLUT_KEY_RIGHT] << endl;
}



void initializeKeySpecialStates() {
	for(int i=0; i<246; i++) keySpecialStates[i] = false;
}

void initializeKeyStates() {
	for(int i=0; i<255; i++) keyStates[i] = false;
}

void specialKeysHandler(int button, int x, int y) {
	keySpecialStates[button] = true;
}

void keyboardHandler(unsigned char button, int x, int y) {
	if(button!=13) {
		keyStates[button] = true;
	}

}

void specialKeysUpHandler(int button, int x, int y) {
	keySpecialStates[button] = false;
}

void keyboardUpHandler(unsigned char button, int x, int y) {
	if(button!=13) {
			keyStates[button] = false;
		}
	else {
		keyStates[button] = true;
	}
}

void performSpecialKeyOperations() {

	m_move *currentmv;
	currentmv = (m_move*)((agentData*)(MainAgent->GetUserData()))->getUserData();

	if(keySpecialStates[GLUT_KEY_UP] && currentmv->isJumping == false) {
		currentmv->m_state[Y_AXIS] = MS_UP;
		currentmv->isJumping = true;
		//playBackgroundSound(phaser);
	}
	else {
		currentmv->m_state[Y_AXIS] = MS_STOP;
	}


	if(keySpecialStates[GLUT_KEY_LEFT]) {
		currentmv->m_state[X_AXIS] = MS_LEFT;
	}

	if(keySpecialStates[GLUT_KEY_RIGHT]) {
		currentmv->m_state[X_AXIS] = MS_RIGHT;
	}

	if(keySpecialStates[GLUT_KEY_LEFT] == keySpecialStates[GLUT_KEY_RIGHT]) {
		currentmv->m_state[X_AXIS] = MS_STOP;
	}
}

MainScreen *mainScreen;
Menu *mainMenu;
Stage *testStage;
DebugDraw drawclass;

void fsmFunction(void) {
	/*
	 * Testing the usage of a FSM to develop a stage system
	 */
	//printf("ok");


	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	//printf("%d\n",++t);

	// State Machine to control Screens
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
			mainScreen->render();
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
			//cout << "Chamou a Init";
			if(!testStage) testStage = new Stage("../maps/test.map","../enemy/enemytest.ene");
			testStage->render();
			break;
	};

	// Looping

	//glFlush();
	glutPostRedisplay();
	glutSwapBuffers();



	/*
	 * End Testing
	 */
}

