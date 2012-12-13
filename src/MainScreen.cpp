/*
 * MainScreen.cpp
 *
 *  Created on: Dec 12, 2012
 *      Author: andre
 */

#include "../inc.h"

MainScreen::MainScreen(Menu *menu) {
	printf("ok");
	mainMenu = menu;
}

void MainScreen::render() {
	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glClearColor (1.0, 1.0,1.0, 0.0);

	glColor3f(0,0,0);


	// Game Title
	glRasterPos2f(20,150);
	string GameTitle = "Welcome to Super Bira World";
	  for (int i = 0; i < GameTitle.length(); i++) {
	    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, GameTitle[i]);
	  }
	  int pos = 90;
	glRasterPos2f(50,pos);

	// Print the Menu
	for(int i=0; i<mainMenu->MenuList->getSize(); i++) {
		string MenuEntry = (static_cast <MenuItem*>(mainMenu->MenuList->seek(i+1)))->menuItemTitle;
		for (int j = 0; j < MenuEntry.length(); j++) {
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, MenuEntry[j]);
			  }
		pos -= 20;
		glRasterPos2f(50,pos);
	}


	glutPostRedisplay();
	glutSwapBuffers();
}

MainScreen::~MainScreen() {
	// TODO Auto-generated destructor stub
	delete this;
}
