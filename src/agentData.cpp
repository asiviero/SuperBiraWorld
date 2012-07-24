/*
 * agentData.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: andre
 */

#include "../inc.h"

agentData::agentData(int aType, void *aData) {
	agentType = aType;
	userData = aData;
}

void *agentData::getUserData() {
	return userData;
}

