/*
 * keyboardHandler.cpp
 *
 *  Created on: Dec 13, 2012
 *      Author: andre
 */


#include "../inc.h"


void initializeKeySpecialStates() {
	for(int i=0; i<246; i++) keySpecialStates[i] = false;
}

void initializeKeyStates() {
	for(int i=0; i<255; i++) keyStates[i] = false;
}

void specialKeysHandler(int button, int x, int y) {
	keySpecialStates[button] = true;
}

void keyboardHandler(unsigned char button, int x, int y) {
		keyStates[button] = true;

}

void specialKeysUpHandler(int button, int x, int y) {
	keySpecialStates[button] = false;
}

void keyboardUpHandler(unsigned char button, int x, int y) {
			keyStates[button] = false;
}

void performSpecialKeyOperations() {

	m_move *currentmv;
	currentmv = (m_move*)((agentData*)(MainAgent->GetUserData()))->getUserData();

	if(keySpecialStates[GLUT_KEY_UP] && currentmv->isJumping == false) {
		currentmv->m_state[Y_AXIS] = MS_UP;
		currentmv->isJumping = true;
		//playBackgroundSound(phaser);
	}
	else {
		currentmv->m_state[Y_AXIS] = MS_STOP;
	}


	if(keySpecialStates[GLUT_KEY_LEFT]) {
		currentmv->m_state[X_AXIS] = MS_LEFT;
	}

	if(keySpecialStates[GLUT_KEY_RIGHT]) {
		currentmv->m_state[X_AXIS] = MS_RIGHT;
	}

	if(keySpecialStates[GLUT_KEY_LEFT] == keySpecialStates[GLUT_KEY_RIGHT]) {
		currentmv->m_state[X_AXIS] = MS_STOP;
	}
}
