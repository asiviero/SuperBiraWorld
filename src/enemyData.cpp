/*
 * enemyData.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: andre
 */

#include "../inc.h"

enemyData::enemyData(float initialPosition[2], float span[2], float speedCoefficient, int movementDirection) {
	fInitialPosition[X_AXIS] = initialPosition[X_AXIS];
	fInitialPosition[Y_AXIS] = initialPosition[Y_AXIS];
	fSpan[X_AXIS] = span[X_AXIS];
	fSpan[Y_AXIS] = span[Y_AXIS];
	fSpeedCoefficient = speedCoefficient;
	intMovementDirection = movementDirection;
	goingForward = true;
	isJumping = true;
}
