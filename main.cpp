/*
 * main.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "inc.h"

agent *mainAgent = new agent(STANDARD_LOSS_COEFFICIENT);

b2Vec2 gravity(0.0f,-9.7f);
bool doSleep = true;
<<<<<<< HEAD
b2World world = b2World(gravity);
b2BodyDef groundBodyDef,bodydeftest;
b2Body* groundBody,*bodyTest2;
b2PolygonShape groundBox,polyTest1;
//list <b2body*> *b2BodyList = new list <b2Body*>;

=======
b2World *world = new b2World(gravity);
b2BodyDef groundBodyDef,MainAgentDef;
b2Body *MainAgent;
b2PolygonShape groundBox,MainAgentShape;
b2FixtureDef MainAgentFixtureDef;
b2Fixture *MainAgentFixture;


float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
int32 velocityIterations = 6;   //how strongly to correct velocity
int32 positionIterations = 3;   //how strongly to correct position

>>>>>>> asiviero


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

<<<<<<< HEAD
	// Creating the "floor" body
	groundBodyDef.position.Set(0,-Y_AXIS_SIZE/2);
	groundBody = world.CreateBody(&groundBodyDef);

	bodydeftest.position.Set(0,0);
	bodyTest2 = world.CreateBody(&bodydeftest);

	// Creates a box, which is to be featured in the floor body
	groundBox.SetAsBox(X_AXIS_SIZE,Y_AXIS_SIZE/2);
	polyTest1.SetAsBox(X_AXIS_SIZE/10,Y_AXIS_SIZE/10);

	// Applies it
	groundBody->CreateFixture(&groundBox,0);
	bodyTest2->CreateFixture(&polyTest1,0);
=======
	m_move *moveTest = new m_move();
	moveTest->m_state[X_AXIS] = moveTest->m_state[Y_AXIS] = MS_STOP;
	// Creating the body
	MainAgentDef.position.Set(X_AXIS_SIZE/2,Y_AXIS_SIZE/2);
	MainAgentDef.type = b2_dynamicBody;

	MainAgent = world->CreateBody(&MainAgentDef);
	MainAgent->SetUserData(moveTest);

	// Creates a box, which is to be featured in the agent body
	MainAgentShape.SetAsBox(4,4);
	MainAgentFixtureDef.friction = 0.2;
	MainAgentFixtureDef.restitution = 0.8;
	MainAgentFixtureDef.shape = &MainAgentShape;

	//polyTest1.SetAsBox(X_AXIS_SIZE/10,Y_AXIS_SIZE/10);

	// Applies it
	MainAgent->CreateFixture(&MainAgentFixtureDef);
	MainAgent->ResetMassData();
>>>>>>> asiviero

	// Sets the class used for debug drawing. It came from Box2d testbed
	DebugDraw drawclass = DebugDraw();
	drawclass.SetFlags(1);
	world.SetDebugDraw(&drawclass);

	// Terrain loading
	char terrainFile[] = "../maps/test.map";
	ifstream terrainMap(terrainFile);
	//cout << "passei!\n";
	if(terrainMap.is_open()) {
		//cout << "map file loaded succesfully, passing it on to function\n";
		loadTerrain(terrainMap,&world);
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

		//cout << "Agent Move: " << MainAgent-> << endl;
		// Draws every object in the world
<<<<<<< HEAD
		world.DrawDebugData();
=======
		//cout << "passei\n";
		cout << ((m_move*)MainAgent->GetUserData())->m_state[X_AXIS] << endl;

		world->Step(timeStep, velocityIterations, positionIterations);
		//cout << "passei\n";
		world->DrawDebugData();
>>>>>>> asiviero

		// Simulator functions end here
		glPopMatrix();
		glutPostRedisplay();
		glutSwapBuffers();

}

void specialKeysHandler(int button, int x, int y) {

	switch(button) {
		case GLUT_KEY_UP:
			pthread_t timerThreadUp;
			//if(mainAgent->floatAgentPosition[Y_AXIS] <=0) mainAgent->setMoveDirectional(UP_CONSTANT,INTENTION);
			pthread_create(&timerThreadUp,NULL,timerJump,MainAgent);
			//mainAgent->setMoveDirectional(UP_CONSTANT,MOVEMENT);
			break;
		case GLUT_KEY_DOWN:
			mainAgent->setMoveDirectional(DOWN_CONSTANT,MOVEMENT);
			break;
		case GLUT_KEY_LEFT:
			pthread_t timerThreadLeft;
			pthread_create(&timerThreadLeft,NULL,timerMoveLeft,MainAgent);
			break;
		case GLUT_KEY_RIGHT:
			pthread_t timerThreadRight;
			pthread_create(&timerThreadRight,NULL,timerMoveRight,MainAgent);
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

