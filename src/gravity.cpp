/*
 * gravity.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: andre
 */

#include "../inc.h"

void agent::setGravity() {
	if(floatAgentPosition[Y_AXIS] <= 0) gravitySet = false;
	else gravitySet = true;
}
