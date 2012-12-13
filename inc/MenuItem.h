/*
 * MenuItem.h
 *
 *  Created on: Dec 11, 2012
 *      Author: andre
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "../inc.h"

class MenuItem {
public:
	string menuItemTitle;
	list <MenuItem*> *subMenuList;


	MenuItem(string title = "", int hasSubList = 0);
	virtual ~MenuItem();
};

#endif /* MENUITEM_H_ */
