/*
 * userInput.h
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#ifndef USERINPUT_H_
#define USERINPUT_H_

void keyboardHandler(unsigned char button, int x, int y);
void specialKeysHandler(int button, int x, int y);
void specialKeysUpHandler(int button, int x, int y);
void initializeKeySpecialStates();
void performSpecialKeyOperations();

#endif /* USERINPUT_H_ */
