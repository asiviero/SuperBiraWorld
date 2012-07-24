/*
 * enemy.cpp
 *
 *  Created on: Jul 24, 2012
 *      Author: andre
 */

#include "../inc.h"

void loadEnemies(ifstream &enemyFile, b2World *world) {
	int nEnemies = 0;
	enemyFile >> nEnemies;
	cout << "Number of Enemies: " << nEnemies << endl;

	float enemyInitialPosition[2], enemySpan[2], speedCoefficient;
	int movementDirection;

	b2BodyDef enemyDef;
	b2Body *enemyTest;
	b2PolygonShape enemyShape;
	b2FixtureDef enemyFixtureDef;
	agentData *enemyDataA;
	enemyData *enemyDataTest;

	//b2Fixture *enemyFixture;

	for (int i = 0; i < nEnemies; i++) {
		enemyFile >> enemyInitialPosition[X_AXIS]
				>> enemyInitialPosition[Y_AXIS] >> enemySpan[X_AXIS]
				>> enemySpan[Y_AXIS] >> speedCoefficient >> movementDirection;

		//cout << enemyInitialPosition[X_AXIS] <<
		enemyDataTest = new enemyData(enemyInitialPosition,enemySpan,speedCoefficient,movementDirection);
		enemyDataA = new agentData(ENEMY, enemyDataTest);

		// Creating the body
		enemyDef.position.Set(enemyInitialPosition[X_AXIS],
				enemyInitialPosition[Y_AXIS]);
		enemyDef.type = b2_dynamicBody;

		enemyTest = world->CreateBody(&enemyDef);
		enemyTest->SetUserData(enemyDataA);

		// Creates a box, which is to be featured in the agent body
		enemyShape.SetAsBox(3, 3);
		enemyFixtureDef.friction = 0.1;
		enemyFixtureDef.density = 0.1;
		enemyFixtureDef.restitution = 0;
		enemyFixtureDef.shape = &enemyShape;

		enemyTest->CreateFixture(&enemyFixtureDef);
		enemyTest->ResetMassData();

		// Setting initial speed
		b2Vec2 enemyInitialVelocity;
		switch (movementDirection) {
			case X_AXIS:
				enemyInitialVelocity.x = speedCoefficient;
				enemyInitialVelocity.y = 0;
				break;
			default:
				enemyInitialVelocity.x = enemyInitialVelocity.y = 0;
				break;
		}
		enemyTest->SetLinearVelocity(enemyInitialVelocity);

		// end for
	}

}
