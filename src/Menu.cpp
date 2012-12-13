/*
 * Menu.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: andre
 */

#include "../inc.h"

Menu::Menu() {
	// TODO Auto-generated constructor stub
	//printf("ok");
	MenuList = new list <MenuItem*>;

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::addMenuItem(string title, int hasSubMenu) {
	MenuItem *newMenuItem = new MenuItem(title,hasSubMenu);
	MenuList->insertList(newMenuItem);
}
