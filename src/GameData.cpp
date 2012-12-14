/*
 * GameData.cpp
 *
 *  Created on: Dec 13, 2012
 *      Author: andre
 */

#include "../inc.h"

GameData::GameData() {
	currentScreen = NULL;
	numberOfLives = 3;
	lastStageBeaten = 0;
}

void GameData::changeGameScreen(Screen *newGameScreen) {
	currentScreen = newGameScreen;
}

GameData::~GameData() {
	// TODO Auto-generated destructor stub
}
