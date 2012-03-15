/*
 * agent.h
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 *
 *  An agent is a controllable object in the simulator.
 *
 *  Its class contains information about its current position, speed, acceleration in space and material properties,
 *  such as its mass;
 *
 */

#ifndef AGENT_H_
#define AGENT_H_

	class agent {
		public:
			float floatAgentPosition[3], floatAgentSpeed[3], floatAgentAcceleration[3], floatAgentForce[3];
			float floatAgentMass, floatAgentFrictionCoefficient[2];
			float floatAgentColor[3];
			float floatBounceTimer;
			float floatEnergyLossBounce;
			bool gravitySet, frictionSet;
			bool boolMoveUp, boolMoveDown, boolMoveLeft, boolMoveRight;
			bool boolMoveUpIntention, boolMoveDownIntention, boolMoveLeftIntention, boolMoveRightIntention;
			float floatTimeForce[3];

		public:
			// Initializing methods
			agent();
			agent(float EnergyLossCoefficient);
			void drawAgent();

			// General functions - implemented in agent.cpp
			void moveAgent();
			void updateMovementVectors();
			int getForceDirection(int axis);
			int getSpeedDirection(int axis);
			float getNormalForce(float angle);
			// This function might be used to establish boundaries in the grid
			// After it has been called, inertia will control the Agent movement
			void resetForces(int axis);

			// Directional movement methods, controlled by user input - implemented in directional.cpp
			void directionalMovement();
			void setMoveDirectional(int dir,int type);
			void resetDirectionalMovement();
			void resetIntention(int dir);

			// Gravity Functions - implemented in gravity.cpp
			void setGravity();

			// Friction functions - implemented in friction.cpp
			void setFriction();
			float getResultingFrictionCoefficient(int material, int mode);

			// Bouncing functions - implemmented in bounce.cpp
			void increaseBounceTimer();
			float energyLossCoefficient();
			void resetBounceTimer();

	};


#endif /* AGENT_H_ */
