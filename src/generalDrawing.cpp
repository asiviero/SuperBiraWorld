/*
 * generalDrawing.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "../inc.h"
#define HORIZONTAL_GRID_LINES 10
#define VERTICAL_GRID_LINES 10

// This function is used to generate a grid for better visualization in the screen
// It's customizable in the way of how many lines the grid should have, which is determined
// by the 2 constants defined in this file. It takes in consideration the Axis sizes (determined
// in constants.h to create the grid.
void drawGrid() {
	float floatGridMarker;
	for(int i=0;i<HORIZONTAL_GRID_LINES;i++) {
		floatGridMarker = i*(X_AXIS_SIZE/HORIZONTAL_GRID_LINES);
		glColor3f(0,0,0);
		glBegin(GL_LINE);
			glVertex2f(floatGridMarker,1e7);
			glVertex2f(floatGridMarker,-1e7);
		glEnd();
	}
	for(int i=0;i<VERTICAL_GRID_LINES;i++) {
		floatGridMarker = i*(Y_AXIS_SIZE/VERTICAL_GRID_LINES);
		glColor3f(0,0,0);
		glBegin(GL_LINE);
			glVertex2f(1e7,floatGridMarker);
			glVertex2f(-1e7,floatGridMarker);
		glEnd();
	}
}

// A very simple function to flush the screen and load the "cube"
void initScreen (void)
{
/*  select clearing (background) color       */
    glClearColor (1.0, 1.0, 1.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, X_AXIS_SIZE, 0, Y_AXIS_SIZE, 0, Z_AXIS_SIZE);
}
