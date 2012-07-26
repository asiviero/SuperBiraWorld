/*
 * contactListener.h
 *
 *  Created on: Jul 26, 2012
 *      Author: andre
 */

#ifndef CONTACTLISTENER_H_
#define CONTACTLISTENER_H_


#include "../inc.h"

class superBiraWorldContactListener : public b2ContactListener {
	public:
		void BeginContact(b2Contact *contact);
};

#endif /* CONTACTLISTENER_H_ */
