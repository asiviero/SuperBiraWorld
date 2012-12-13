/*
 * MainScreen.h
 *
 *  Created on: Dec 12, 2012
 *      Author: andre
 */

#ifndef MAINSCREEN_H_
#define MAINSCREEN_H_

#include "../inc.h"

class MainScreen {
public:
	Menu *mainMenu;
	MainScreen(Menu *menu = NULL);
	virtual void render();
	virtual ~MainScreen();
};

#endif /* MAINSCREEN_H_ */
