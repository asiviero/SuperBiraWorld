/*
 * MenuItem.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: andre
 */

#include "../inc.h"

MenuItem::MenuItem(string title, int hasSubList) {
	// TODO Auto-generated constructor stub
	//subMenuList = NULL;
	menuItemTitle = title;
	if(hasSubList == HAS_SUB_LIST) {
		subMenuList = new list <MenuItem*>;
	}
	else subMenuList = NULL;

}

MenuItem::~MenuItem() {
	// TODO Auto-generated destructor stub

}
