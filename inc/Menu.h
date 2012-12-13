/*
 * Menu.h
 *
 *  Created on: Dec 11, 2012
 *      Author: andre
 */

#ifndef MENU_H_
#define MENU_H_

#include "../inc.h"

class Menu {
public:
	list <MenuItem*> *MenuList;
	Menu();
	virtual ~Menu();
	void addMenuItem(string title, int hasSubMenu);
};

#endif /* MENU_H_ */
