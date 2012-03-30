/*
 * main.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "inc.h"

agent *mainAgent = new agent(STANDARD_LOSS_COEFFICIENT);

b2Vec2 gravity(0.0f,-9.8f);
bool doSleep = true;
b2World *world = new b2World(gravity);
b2BodyDef groundBodyDef,MainAgentDef;
b2Body *MainAgent;
b2PolygonShape groundBox,MainAgentShape;
//list <b2body*> *b2BodyList = new list <b2Body*>;

float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
int32 velocityIterations = 8;   //how strongly to correct velocity
int32 positionIterations = 3;   //how strongly to correct position



void display(void);
void loadTerrain(ifstream &map,b2World *world);

int main(int argc, char** argv) {
	// Init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200,800);
	glutInitWindowSize(MAIN_WINDOW_WIDTH,MAIN_WINDOW_HEIGHT);
	int intMainWindowID;
	intMainWindowID = glutCreateWindow("Physics Simulator");

	// Handler Functions
	glutKeyboardFunc(keyboardHandler);
	glutSpecialFunc(specialKeysHandler);

	// box2d functions

	// Creating the "floor" body
	MainAgentDef.position.Set(X_AXIS_SIZE/2,Y_AXIS_SIZE/2);
	MainAgentDef.type = b2_dynamicBody;
	MainAgent = world->CreateBody(&MainAgentDef);

	// Creates a box, which is to be featured in the agent body
	MainAgentShape.SetAsBox(4,4);
	//polyTest1.SetAsBox(X_AXIS_SIZE/10,Y_AXIS_SIZE/10);

	// Applies it
	MainAgent->CreateFixture(&MainAgentShape,0);
	//bodyTest2->CreateFixture(&polyTest1,0);

	// Sets the class used for debug drawing. It came from Box2d testbed
	DebugDraw drawclass = DebugDraw();
	drawclass.SetFlags(1);
	world->SetDebugDraw(&drawclass);

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

	// Rendering
	initScreen();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void display(void)
{
/*  clear all pixels  */

		glClear (GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		// Simulator functions begin here
		drawGrid();
		//mainAgent->drawAgent();		mainAgent->moveAgent();

		// Draws every object in the world
		world->Step(timeStep, velocityIterations, positionIterations);
		world->DrawDebugData();

		// Simulator functions end here
		glPopMatrix();
		glutPostRedisplay();
		glutSwapBuffers();

}

void specialKeysHandler(int button, int x, int y) {

	switch(button) {
		case GLUT_KEY_UP:
			pthread_t timerThreadUp;
			if(mainAgent->floatAgentPosition[Y_AXIS] <=0) mainAgent->setMoveDirectional(UP_CONSTANT,INTENTION);
			pthread_create(&timerThreadUp,NULL,timer,mainAgent);
			//mainAgent->setMoveDirectional(UP_CONSTANT,MOVEMENT);
			break;
		case GLUT_KEY_DOWN:
			mainAgent->setMoveDirectional(DOWN_CONSTANT,MOVEMENT);
			break;
		case GLUT_KEY_LEFT:
			pthread_t timerThreadLeft;
			mainAgent->setMoveDirectional(LEFT_CONSTANT,INTENTION);
			pthread_create(&timerThreadLeft,NULL,timer,mainAgent);
			break;
		case GLUT_KEY_RIGHT:
			pthread_t timerThreadRight;
			mainAgent->setMoveDirectional(RIGHT_CONSTANT,INTENTION);
			pthread_create(&timerThreadRight,NULL,timer,mainAgent);
			break;
		case GLUT_KEY_END:
			mainAgent->resetForces(X_AXIS);
			mainAgent->resetForces(Y_AXIS);
			break;
		default:
			mainAgent->setMoveDirectional(NULL,NULL);
	}
}

void keyboardHandler(unsigned char button, int x, int y) {
	switch(button) {
		case ESC_KEY:
			delete world;
			exit(0);
			break;
		case 's':
		pthread_t timerThreadUp;
		if(mainAgent->floatAgentPosition[Y_AXIS] <=0) mainAgent->setMoveDirectional(UP_CONSTANT,INTENTION);
		pthread_create(&timerThreadUp,NULL,timer,mainAgent);
		//mainAgent->setMoveDirectional(UP_CONSTANT,MOVEMENT);
		break;
	}

}

