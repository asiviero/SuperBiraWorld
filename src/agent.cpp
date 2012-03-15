/*
 * agent.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "../inc.h"

agent::agent() {
	// Reset all vars, except the mass
	for(int i=0;i<3;i++) {
		floatAgentAcceleration[i] = 0;
		floatAgentSpeed[i] = 0;
		floatAgentColor[i] = 0;
		floatAgentPosition[i] = 0;
	}
	floatAgentPosition[Y_AXIS] = 0;//Y_AXIS_SIZE;
	floatAgentMass = AGENT_MASS;
	floatAgentFrictionCoefficient[STATIC] = AGENT_FRICTION_COEFFICIENT_STATIC;
	floatAgentFrictionCoefficient[DYNAMIC] = AGENT_FRICTION_COEFFICIENT_DYNAMIC;
	floatBounceTimer = 0;
	gravitySet = true;
}

agent::agent(float EnergyLossCoefficient) {
	// Reset all vars, except the mass
	for(int i=0;i<3;i++) {
		floatAgentAcceleration[i] = 0;
		floatAgentSpeed[i] = 0;
		floatAgentColor[i] = 0;
		floatAgentPosition[i] = 0;
	}
	floatAgentPosition[Y_AXIS] = 0;//Y_AXIS_SIZE;
	floatAgentMass = AGENT_MASS;
	floatAgentFrictionCoefficient[STATIC] = AGENT_FRICTION_COEFFICIENT_STATIC;
	floatAgentFrictionCoefficient[DYNAMIC] = AGENT_FRICTION_COEFFICIENT_DYNAMIC;
	floatBounceTimer = 0;
	gravitySet = true;
	floatEnergyLossBounce = EnergyLossCoefficient;
	floatTimeForce[X_AXIS] = AGENT_FORCE_TIME_X;
	floatTimeForce[Y_AXIS] = AGENT_FORCE_TIME_Y;
}


// Since the agent can be represented as a single spot in the screen, this is very simple to draw
// Its color and size can be altered in inc/constants.h
void agent::drawAgent() {
	glPointSize(AGENT_SIZE);
	glBegin(GL_POINTS);
		glColor3f(floatAgentColor[RED_PCT],floatAgentColor[GREEN_PCT],floatAgentColor[BLUE_PCT]);
		glVertex3f(floatAgentPosition[X_AXIS],floatAgentPosition[Y_AXIS],floatAgentPosition[Z_AXIS]);
	glEnd();
}

// This is the main movement function, and it'll get bigger and more complex as
// features are added. Currently it can be summed as:

/*
 * Working: Gravity, Directional Control, Horizontal Friction
 *
 * To be implemented: Bouncing and Collision
 *
 */
void agent::moveAgent() {
	float auxFrictionForce=0, floatPrevSpeed=0, floatCurrentSpeed=0;
	// Determines if the agent should or should not suffer gravity effect. Boolean var gravitySet is updated
	setGravity();

	// Determines if the agent should or should not suffer friction effect. Boolean var frictionSet is updated
	setFriction();

	// setting gravity effect
	if(gravitySet) {
		floatAgentForce[Y_AXIS] -= EARTH_GRAVITY/floatAgentMass;
	}

	// check for ground
	if(floatAgentPosition[Y_AXIS] <= 0) {
		//reset speed and acceleration vectors in Y axis
		floatAgentAcceleration[Y_AXIS] = floatAgentSpeed[Y_AXIS] = 0;

		//Calculate the loss of speed based on the timer
		/*floatAgentSpeed[Y_AXIS] *= -1*energyLossCoefficient();
		if(floatAgentSpeed[Y_AXIS] < 1) {
			floatAgentSpeed[Y_AXIS] = 0;
			resetBounceTimer();
		}*/
	}
	/*else {
		// Starts bounce timer
		increaseBounceTimer();
	}*/
	//if(floatBounceTimer > 0.4) resetBounceTimer();

	// After ground checking, directional control is applied, in a manner that ground
	// effect of nulling speed and acceleration in the Y axis won't affect further movement
	directionalMovement();

	// set friction effect
	if(frictionSet) {

		if(abs(floatAgentForce[X_AXIS]) <= getResultingFrictionCoefficient(EARTH,STATIC)*getNormalForce(0) && floatAgentSpeed[X_AXIS] == 0) {
			//auxFrictionForce = floatAgentForce[X_AXIS];
			//resetForces(X_AXIS);
		}
		else {
			//cout << "ĥey there" << endl;
			//sleep(1);
			auxFrictionForce = getSpeedDirection(X_AXIS) * getResultingFrictionCoefficient(EARTH,DYNAMIC) * getNormalForce(0);
			floatAgentForce[X_AXIS] -= auxFrictionForce;
		}

	}

	floatPrevSpeed = floatAgentSpeed[X_AXIS];

	// Updates the movement vectors (acceleration, speed and position)
	updateMovementVectors();

	floatCurrentSpeed = floatAgentSpeed[X_AXIS];

	// removing gravity effect
	if(gravitySet) {
		floatAgentForce[Y_AXIS] += EARTH_GRAVITY/floatAgentMass;
	}

	// removing friction effect
	if(frictionSet) {
		floatAgentForce[X_AXIS] += auxFrictionForce;
		if(floatAgentForce[X_AXIS] == 0 && (floatPrevSpeed * floatCurrentSpeed < 0)) floatAgentAcceleration [X_AXIS] = floatAgentSpeed[X_AXIS] = 0;
	}

	// resetting input forces
	//resetDirectionalMovement();

	cout << floatAgentSpeed[X_AXIS] << " "<< floatAgentPosition[X_AXIS] << endl;
	//if(boolMoveUp) sleep(1);
	//if(floatAgentSpeed[X_AXIS] !=0) resetForces(X_AXIS);

	// this is for testing gravity
	if(floatAgentPosition[Y_AXIS] > Y_AXIS_SIZE/3) resetForces(Y_AXIS);

	// this is for testing friction
	//if(floatAgentPosition[X_AXIS] > X_AXIS_SIZE/3) resetForces(X_AXIS);
}

// Basic function to update the vectors, from lowest to highest level
void agent::updateMovementVectors() {
	for(int i=0;i<3;i++) {
		floatAgentAcceleration[i] = floatAgentForce[i]/floatAgentMass;
		floatAgentSpeed[i] += floatAgentAcceleration[i];
		floatAgentPosition[i] += floatAgentSpeed[i];
	}
}

void agent::resetForces(int axis) {
	floatAgentForce[axis] = 0;
}

int agent::getForceDirection(int axis) {
	if(floatAgentForce[axis]!=0)
	return (abs(floatAgentForce[axis])/floatAgentForce[axis]);
	else return 0;
}

int agent::getSpeedDirection(int axis) {
	if(floatAgentSpeed[axis]!=0)
	return (abs(floatAgentSpeed[axis])/floatAgentSpeed[axis]);
	else return 0;
}

float agent::getNormalForce(float angle) {
	return (floatAgentMass * EARTH_GRAVITY * cos(angle));
}
