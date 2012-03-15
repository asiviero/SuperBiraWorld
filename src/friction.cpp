/*
 * friction.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: andre
 */

#include "../inc.h"

float getFrictionCoefficient(int material, int mode) {
	float frictionCoefficientIndex[100][2];
	frictionCoefficientIndex[EARTH][STATIC] = 1;
	frictionCoefficientIndex[EARTH][DYNAMIC] = 0.9;
	frictionCoefficientIndex[RUBBER][STATIC] = 1.5;
	frictionCoefficientIndex[RUBBER][DYNAMIC] = 1.4;
	frictionCoefficientIndex[LUBE][STATIC] = 0.2;
	frictionCoefficientIndex[LUBE][DYNAMIC] = 0.1;
	frictionCoefficientIndex[LEATHER][STATIC] = 1.2;
	frictionCoefficientIndex[LEATHER][DYNAMIC] = 1.1;
	return frictionCoefficientIndex[material][mode];
}

// In many ways, friction is an analogous to gravity, so the ways of applying it are similar
void agent::setFriction() {
	if(floatAgentPosition[Y_AXIS] > 0) frictionSet = false;
	else frictionSet = true;
}

float agent::getResultingFrictionCoefficient(int material, int mode) {
	return (sqrt(floatAgentFrictionCoefficient[mode]*getFrictionCoefficient(material,mode)));
}
