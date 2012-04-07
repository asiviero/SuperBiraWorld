/*
 * directional.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: andre
 */

#include "../inc.h"

// This function controls if and where to the agent should move
void agent::setMoveDirectional(int dir,int type) {
	if(type == MOVEMENT) {
		switch(dir) {
			case UP_CONSTANT:
				if(boolMoveDown) {
					boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
					break;
				}
				boolMoveUp = true;
				boolMoveDown = false;
				boolMoveLeft = false;
				boolMoveRight = false;
				break;
			case DOWN_CONSTANT:
				if(boolMoveUp) {
					boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
					break;
				}
				boolMoveUp = false;
				boolMoveDown = true;
				boolMoveLeft = false;
				boolMoveRight = false;
				break;
			case LEFT_CONSTANT:
				if(boolMoveRight) {
					boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
					break;
				}
				boolMoveUp = false;
				boolMoveDown = false;
				boolMoveLeft = true;
				boolMoveRight = false;
				break;
			case RIGHT_CONSTANT:
				//cout << "Entered Right" << endl;
				//sleep(1);
				if(boolMoveLeft) {
					boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
					break;
				}
				boolMoveUp = false;
				boolMoveDown = false;
				boolMoveLeft = false;
				boolMoveRight = true;
				break;
			default:
				boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
				break;
		}
	}
	else {
		switch(dir) {
			case UP_CONSTANT:
				if(boolMoveDownIntention) {
					boolMoveUpIntention = boolMoveDownIntention = boolMoveLeftIntention = boolMoveRightIntention = false;
					break;
				}
				boolMoveUpIntention = true;
				/*boolMoveDownIntention = false;
				boolMoveLeftIntention = false;
				boolMoveRightIntention = false;*/
				break;
			case DOWN_CONSTANT:
				if(boolMoveUpIntention) {
					boolMoveUpIntention = boolMoveDownIntention = boolMoveLeftIntention = boolMoveRightIntention = false;
					break;
				}
				//boolMoveUpIntention = false;
				boolMoveDownIntention = true;
				//boolMoveLeftIntention = false;
				//boolMoveRightIntention = false;
				break;
			case LEFT_CONSTANT:
				if(boolMoveRightIntention) {
					boolMoveUpIntention = boolMoveDownIntention = boolMoveLeftIntention = boolMoveRightIntention = false;
					break;
				}
				//boolMoveUpIntention = false;
				//boolMoveDownIntention = false;
				boolMoveLeftIntention = true;
				//boolMoveRightIntention = false;
				break;
			case RIGHT_CONSTANT:
				//cout << "Entered Right" << endl;
				//sleep(1);
				if(boolMoveLeftIntention) {
					boolMoveUpIntention = boolMoveDownIntention = boolMoveLeftIntention = boolMoveRightIntention = false;
					break;
				}
				/*boolMoveUpIntention = false;
				boolMoveDownIntention = false;
				boolMoveLeftIntention = false;*/
				boolMoveRightIntention = true;
				break;
			default:
				boolMoveUpIntention = boolMoveDownIntention = boolMoveLeftIntention = boolMoveRightIntention = false;
				break;
		}
	}
}

// Apply what was defined in setMoveDirectional
void agent::directionalMovement() {
	if(boolMoveUp && boolMoveUpIntention) {
		//cout << "oh mama!" << endl;
		floatAgentForce[Y_AXIS] += boolMoveUp*STD_FORCE_VERTICAL;
	}
	//floatAgentForce[Y_AXIS] -= boolMoveDown*STD_FORCE_VERTICAL;

	if(boolMoveRight)
	floatAgentSpeed[X_AXIS] = boolMoveRight*STD_FORCE_HORIZONTAL;
	if(boolMoveLeft)
	floatAgentSpeed[X_AXIS] = -boolMoveLeft*STD_FORCE_HORIZONTAL;
	//cout << "Entered: " << boolMoveRight << " Speed: " << floatAgentSpeed[X_AXIS] << endl;
}

void agent::resetDirectionalMovement() {
	boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
	//boolMoveUpIntention = boolMoveDownIntention = boolMoveLeftIntention = boolMoveRightIntention = false;
}

void agent::resetIntention(int dir) {
	switch(dir) {
		case UP_CONSTANT:
			boolMoveUpIntention = false;
			break;
		case DOWN_CONSTANT:
			boolMoveDownIntention = false;
			break;
		case LEFT_CONSTANT:
			boolMoveLeftIntention = false;
			break;
		case RIGHT_CONSTANT:
			boolMoveRightIntention = false;
			break;
	}
}

void *timerMoveRight(void *ag) {

		cout << "timer on!" << endl;
		clock_t endwait;
		b2Body *agent = (b2Body*)ag;
		m_move *mvtmp = new m_move();
		mvtmp->m_state[X_AXIS] = MS_RIGHT;
		agent->SetUserData(mvtmp);


		endwait = clock () + 0.2 * CLOCKS_PER_SEC;

	  	while (clock() < endwait);
	  	cout << "timer out!" << endl;
	  	mvtmp->m_state[X_AXIS] = MS_STOP;
	  	agent->SetUserData(mvtmp);
	  	delete mvtmp;
	  	return NULL;
}

void *timerMoveLeft(void *ag) {

	cout << "timer on!" << endl;
	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *mvtmp = new m_move();
	mvtmp->m_state[X_AXIS] = MS_LEFT;
	agent->SetUserData(mvtmp);


	endwait = clock () + 0.2 * CLOCKS_PER_SEC;

  	while (clock() < endwait);
  	cout << "timer out!" << endl;
  	mvtmp->m_state[X_AXIS] = MS_STOP;
  	agent->SetUserData(mvtmp);
  	delete mvtmp;
  	return NULL;
}

void *timerJump(void *ag) {

	cout << "timer on!" << endl;
	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *mvtmp = new m_move();
	mvtmp->m_state[Y_AXIS] = MS_UP;
	agent->SetUserData(mvtmp);


	endwait = clock () + 0.2 * CLOCKS_PER_SEC;

  	while (clock() < endwait);
  	cout << "timer out!" << endl;
  	mvtmp->m_state[Y_AXIS] = MS_STOP;
  	agent->SetUserData(mvtmp);
  	delete mvtmp;
  	return NULL;
}
