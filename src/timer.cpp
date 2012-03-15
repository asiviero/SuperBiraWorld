/*
 * timer.cpp
 *
 *  Created on: Mar 13, 2012
 *      Author: andre
 */

#include "../inc.h"

void *timer(void *ag) {

		//cout << "timer on!" << endl;
		agent *mainAgentT = (agent*)ag;
		clock_t endwait;

		int constant;
		if(mainAgentT->boolMoveUpIntention) {constant = UP_CONSTANT;}
		if(mainAgentT->boolMoveDownIntention) constant = DOWN_CONSTANT;
		if(mainAgentT->boolMoveLeftIntention) constant = LEFT_CONSTANT;
		if(mainAgentT->boolMoveRightIntention) constant = RIGHT_CONSTANT;

		endwait = clock () + mainAgentT->floatTimeForce[constant/2] * CLOCKS_PER_SEC;

	  	while (clock() < endwait) {
	  		mainAgentT->setMoveDirectional(constant,MOVEMENT);
	  	};
	  	//cout << "timer out!" << endl;

	  	mainAgentT->resetIntention(constant);
	  	mainAgentT->resetDirectionalMovement();
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
