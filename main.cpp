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

b2Vec2 gravity(0.0f,-9.7f);
bool doSleep = true;
b2World *world = new b2World(gravity);
b2Body *MainAgent;
GameData gameData;
MainScreen *mainScreen;
Menu *mainMenu;
Stage *testStage;
DebugDraw drawclass;

float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
int32 velocityIterations = 6;   //how strongly to correct velocity
int32 positionIterations = 3;   //how strongly to correct position

gameScreenEnum gameScreen = Start_Screen;

int phaserChannel = -1;

int main(int argc, char** argv) {

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

