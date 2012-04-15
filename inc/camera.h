/*
 * camera.h
 *
 *  Created on: Apr 14, 2012
 *      Author: andre
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <Box2D/Box2D.h>

class camera {
	protected:
		float fCamPosition[3];
		float fCamSpeed[3];
	public:
		camera();
		void checkForBorder(float pct, b2Body *Agent);
		void shiftCamera();
};

void shiftCamera();

#endif /* CAMERA_H_ */
