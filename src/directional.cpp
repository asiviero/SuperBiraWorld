/*
 * directional.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: andre
 */

#include "../inc.h"

void *timerMoveRight(void *ag) {

	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *currentmv;
	currentmv = (m_move*)agent->GetUserData();
	currentmv->m_state[X_AXIS] = MS_RIGHT;

	endwait = clock () + AGENT_FORCE_TIME_X * CLOCKS_PER_SEC;

  	while (clock() < endwait);
  	currentmv->m_state[X_AXIS] = MS_STOP;
  	return NULL;
}

void *timerMoveLeft(void *ag) {

	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *currentmv;
	currentmv = (m_move*)agent->GetUserData();
	currentmv->m_state[X_AXIS] = MS_LEFT;

	endwait = clock () + AGENT_FORCE_TIME_X * CLOCKS_PER_SEC;

  	while (clock() < endwait);
  	currentmv->m_state[X_AXIS] = MS_STOP;
  	return NULL;
}

void *timerJump(void *ag) {


	clock_t endwait;
	b2Body *agent = (b2Body*)ag;
	m_move *currentmv;
	currentmv = (m_move*)agent->GetUserData();
	currentmv->m_state[Y_AXIS] = MS_UP;

	endwait = clock () + AGENT_FORCE_TIME_Y * CLOCKS_PER_SEC;

  	while (clock() < endwait);

  	currentmv->m_state[Y_AXIS] = MS_STOP;
  	return NULL;
}
