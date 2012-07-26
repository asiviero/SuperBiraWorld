/*
 * agentData.h
 *
 *  Created on: Jul 23, 2012
 *      Author: andre
 */

#ifndef AGENTDATA_H_
#define AGENTDATA_H_


class agentData {
	public:
		int agentType;
		bool scheduledForDestruction;
		void *userData;
		agentData(int aType, void *aData);
		void *getUserData();
};

#endif /* AGENTDATA_H_ */
