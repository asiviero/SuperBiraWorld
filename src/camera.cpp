/*
 * camera.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: andre
 */

#include "../inc.h"


camera::camera() {
	for(int i=0; i<3; i++) fCamSpeed[i] = fCamPosition[i] = 0.0;
}

void camera::checkForBorder(float pct, b2Body *Agent) {
	if((Agent->GetPosition()(X_AXIS) >= pct * (fCamPosition[X_AXIS]+X_AXIS_SIZE)) ||
		Agent->GetPosition()(X_AXIS) <= (1 - pct) * (fCamPosition[X_AXIS]+X_AXIS_SIZE)) {
		//sleep(2);
		fCamSpeed[X_AXIS] = Agent->GetLinearVelocity()(X_AXIS);
		//cout << "camera speed: " << fCamSpeed[X_AXIS] << " camera position: " << fCamPosition[X_AXIS] << endl;
	}
}

void camera::shiftCamera() {
	for(int i=0;i<3;i++) fCamPosition[i] += (fCamSpeed[i]/(20 * CLOCKS_PER_SEC));
}

void shiftCamera() {
	glTranslatef(0,1,0);
}
