/*
 * keyboardHandler.h
 *
 *  Created on: Dec 13, 2012
 *      Author: andre
 */

#ifndef KEYBOARDHANDLER_H_
#define KEYBOARDHANDLER_H_


#include "../inc.h"


void initializeKeySpecialStates();
void initializeKeyStates();
void specialKeysHandler(int button, int x, int y);
void keyboardHandler(unsigned char button, int x, int y);
void specialKeysUpHandler(int button, int x, int y);
void keyboardUpHandler(unsigned char button, int x, int y);
void performSpecialKeyOperations();


#endif /* KEYBOARDHANDLER_H_ */
