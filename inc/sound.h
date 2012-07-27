/*
 * sound.h
 *
 *  Created on: Jul 27, 2012
 *      Author: andre
 */

#ifndef SOUND_H_
#define SOUND_H_


//#include "../inc.h"
// Sound Libs
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

void playBackgroundSound(Mix_Chunk *phaser);
void prepareSoundDevice();
void playBackgroundMusic(char *soundName);
void musicDone();


#endif /* SOUND_H_ */
