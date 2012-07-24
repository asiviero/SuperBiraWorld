/*
 * enemyData.h
 *
 *  Created on: Jul 23, 2012
 *      Author: andre
 */

#ifndef ENEMYDATA_H_
#define ENEMYDATA_H_

class enemyData {
	public:
		bool goingForward;
		float fInitialPosition[2];
		float fSpan[2];
		float fSpeedCoefficient;
		int intMovementDirection;
		bool isJumping;
		enemyData(float initialPosition[2], float span[2], float speedCoefficient, int movementDirection);
};


#endif /* ENEMYDATA_H_ */
