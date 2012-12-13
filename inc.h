/*
 * inc.h
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#ifndef INC_H_
#define INC_H_

// System Libs
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <cmath>
#include <pthread.h>
#include <time.h>

// Graphic Libs
#include <GL/gl.h>
#include <GL/glut.h>
#include "Box2D/Box2D.h"

// Sound Libs
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>


// User Libs
#include "inc/constants.h"
#include "inc/friction.h"
#include "inc/userInput.h"
#include "inc/generalDrawing.h"
#include "inc/agent.h"
#include "inc/timer.h"
#include "inc/list.h"
#include "inc/terrain.h"
#include "inc/m_move.h"
#include "inc/directional.h"
#include "inc/camera.h"
#include "inc/enemyData.h"
#include "inc/agentData.h"
#include "inc/enemy.h"
#include "inc/contactListener.h"
#include "inc/sound.h"
#include "inc/MenuItem.h"
#include "inc/Menu.h"
#include "inc/GeneralScreen.h"
#include "inc/MainScreen.h"
#include "inc/Stage.h"




#include "Render.h"


enum _moveState {
    MS_STOP,
    MS_UP,
    MS_LEFT,
    MS_RIGHT,
  };

enum gameScreenEnum {

	Start_Screen,
	Load_Screen,
	Stage_Selection_Screen,
	Stage_Screen,
	Save_Screen,
	Game_Over_Screen,
	Settings_Screen
};

// Global vars
extern bool keySpecialStates[246];
extern bool keyStates[255];
extern b2World *world;
extern b2Body *MainAgent;
extern DebugDraw drawclass;

#endif /* INC_H_ */
