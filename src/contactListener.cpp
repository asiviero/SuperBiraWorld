/*
 * contactListener.cpp
 *
 *  Created on: Jul 26, 2012
 *      Author: andre
 */

#include "../inc.h"

void superBiraWorldContactListener::BeginContact(b2Contact *contact) {

	agentData *dataA = static_cast<agentData*>(contact->GetFixtureA()->GetBody()->GetUserData());
	agentData *dataB = static_cast<agentData*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if(dataA->agentType == MAIN_AGENT) { // || dataB->agentType == MAIN_AGENT) {
		if(dataB->agentType == ENEMY) {

			b2WorldManifold worldManifold;
			contact->GetWorldManifold(&worldManifold);

			// todo This can be improved
			// a possible bug would feature the main agent hitting the enemies while falling, but on their side
			// which should result in main agent's death but will result in enemy's death
			if(worldManifold.normal.y < 0) {
				((agentData*)(contact->GetFixtureB()->GetBody()->GetUserData()))->scheduledForDestruction = true;
			}
		}
	}
	//if(dataB->agentType == MAIN_AGENT) cout << "UBIRAJARA APARECENDO NO B!\n";
}
