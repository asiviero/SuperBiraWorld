/*
 * directional.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: andre
 */

#include "../inc.h"

void *timerMoveRight(void *ag) {
	cout << "timer on Right! \n";
	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *currentmv;
	currentmv = (m_move*)((agentData*)(agent->GetUserData()))->getUserData();
	currentmv->m_state[X_AXIS] = MS_RIGHT;

	endwait = clock () + AGENT_FORCE_TIME_X * CLOCKS_PER_SEC;

  	while (clock() < endwait);
  	currentmv->m_state[X_AXIS] = MS_STOP;

	cout << "timer off Right! \n";

  	return NULL;
}

void *timerMoveLeft(void *ag) {
	cout << "timer on Left! \n";
	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *currentmv;
	currentmv = (m_move*)((agentData*)(agent->GetUserData()))->getUserData();
	currentmv->m_state[X_AXIS] = MS_LEFT;

	endwait = clock () + AGENT_FORCE_TIME_X * CLOCKS_PER_SEC;

  	while (clock() < endwait);
  	currentmv->m_state[X_AXIS] = MS_STOP;

	cout << "timer off Left! \n";

  	return NULL;
}

void *timerJump(void *ag) {

	cout << "timer on Up! \n";
	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *currentmv;
	currentmv = (m_move*)((agentData*)(agent->GetUserData()))->getUserData();

	if(currentmv->isJumping == false) {
		currentmv->m_state[Y_AXIS] = MS_UP;
		currentmv->isJumping = true;
	}
	else return NULL;

	endwait = clock () + AGENT_FORCE_TIME_Y * CLOCKS_PER_SEC;

  	while (clock() < endwait);

  	currentmv->m_state[Y_AXIS] = MS_STOP;

	cout << "timer off Up! \n";

  	return NULL;
}
