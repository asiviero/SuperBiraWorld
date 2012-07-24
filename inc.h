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

#include <Box2D/Box2D.h>


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

#include "Render.h"


enum _moveState {
    MS_STOP,
    MS_UP,
    MS_LEFT,
    MS_RIGHT,
  };



#endif /* INC_H_ */
