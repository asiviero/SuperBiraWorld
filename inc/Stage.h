/*
 * Stage.h
 *
 *  Created on: Dec 10, 2012
 *      Author: andre
 */

#ifndef STAGE_H_
#define STAGE_H_

class Stage {
public:
	// Properties
	string enemiesFile, terrainFile;
	//b2Body *MainAgent;
	//b2World *world;
	const static float32 timeStep = 1/20.0;      //the length of time passed to simulate (seconds)
	const static int32 velocityIterations = 6;   //how strongly to correct velocity
	const static int32 positionIterations = 3;   //how strongly to correct position


	Stage(char terrainFileIn[], char enemyFileIn[]);
	virtual void render();
	virtual ~Stage();
};

#endif /* STAGE_H_ */
