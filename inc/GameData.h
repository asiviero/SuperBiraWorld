/*
 * GameData.h
 *
 *  Created on: Dec 13, 2012
 *      Author: andre
 */

#ifndef GAMEDATA_H_
#define GAMEDATA_H_

#include "../inc.h"

class GameData {
public:
	Screen *currentScreen;
	int numberOfLives;
	int lastStageBeaten;

	GameData();
	void changeGameScreen(Screen *newGameScreen);
	virtual ~GameData();
};

#endif /* GAMEDATA_H_ */
