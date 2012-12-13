/*
 * Stage.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: andre
 */

#include "../inc.h"

Stage::Stage(char terrainFile[], char enemyFile[]) {

	//b2Vec2 gravity(0.0f,-9.7f);
	//world = new b2World(gravity);
	b2BodyDef groundBodyDef,MainAgentDef,enemyDef;
	b2PolygonShape groundBox,MainAgentShape,enemyShape;
	b2FixtureDef MainAgentFixtureDef,enemyFixtureDef;

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
		drawclass = DebugDraw();
		drawclass.SetFlags(1);
		world->SetDebugDraw(&drawclass);

		superBiraWorldContactListener *listener = new superBiraWorldContactListener();
		world->SetContactListener(listener);


		// Terrain loading
		//string terrainFile = terrain;
		ifstream terrainMap(terrainFile);
		//cout << "passei!\n";
		if(terrainMap.is_open()) {
			//cout << "map file loaded succesfully, passing it on to function\n";
			loadTerrain(terrainMap,world);
		}
		terrainMap.close();
		//cout << "passei!\n";

		// Enemy loading
		//string enemyFile = enemy;
		ifstream enemyFileStream(enemyFile);
		//cout << "passei!\n";
		if(enemyFileStream.is_open()) {
			//cout << "map file loaded succesfully, passing it on to function\n";
			loadEnemies(enemyFileStream,world);
		}
		enemyFileStream.close();

		// Sound
		prepareSoundDevice();
		playBackgroundMusic("../UbirajaraAparecendo.mp3");

}

Stage::~Stage() {
	// TODO Auto-generated destructor stub
	//delete this;
}

void Stage::render() {
	//glClear (GL_COLOR_BUFFER_BIT);
		//	glPushMatrix();

			glClearColor(1,1,1,0);
			// Simulator functions begin here
			drawGrid();

			// Draws every object in the world

			world->DrawDebugData();

			// Simulator functions end here

			glPopMatrix();

			world->Step(timeStep, velocityIterations, positionIterations);

}
