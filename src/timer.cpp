/*
 * timer.cpp
 *
 *  Created on: Mar 13, 2012
 *      Author: andre
 */

#include "../inc.h"

void *timer(void *ag) {

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

/*void *moveAgentLeftThread(void *ag) {

		cout << "timer on!" << endl;
		agent *mainAgentT = (agent*)ag;
		clock_t endwait;
		endwait = clock () + mainAgentT->floatTimeForce * CLOCKS_PER_SEC ;
	  	while (clock() < endwait) {
	  		mainAgentT->setMoveDirectional(LEFT_CONSTANT,MOVEMENT);
	  	};
	  	cout << "timer out!" << endl;
	  	mainAgentT->resetDirectionalMovement();
	  	return NULL;
}
*/
