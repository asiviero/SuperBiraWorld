/*
 * terrain.cpp
 *
 *  Created on: Mar 28, 2012
 *      Author: andre
 */

#include "../inc.h"

void loadTerrain(ifstream &map,b2World *world) {
	int32 intNBodiesOnTerrain=0;
	int intNVertexPolygon;
	float fVertexCoordinates[2];
	b2FixtureDef fixture;
	b2PolygonShape polygon;
	b2BodyDef bodydef;
	b2Body *body;
	// Check for number of bodies in terrain
	map >> intNBodiesOnTerrain;
	for(int i=0;i<intNBodiesOnTerrain;i++) {
		agentData *agentD = new agentData(TERRAIN,NULL);
		// Check for number of vertices
		map >> intNVertexPolygon;
		// Initialize vector
		b2Vec2 vector2dVertexPosition[intNVertexPolygon];
		for(int j=0;j<intNVertexPolygon;j++) {
			// for each vertex, scan coordinates and fill vector
			map >> fVertexCoordinates[X_AXIS] >> fVertexCoordinates[Y_AXIS];
			vector2dVertexPosition[j].Set(fVertexCoordinates[X_AXIS],fVertexCoordinates[Y_AXIS]);
		}
		// defining a body
		// further improvement could be done about centroids
		polygon.Set(vector2dVertexPosition,intNVertexPolygon);

		fixture.friction = 0.7;
		fixture.shape = &polygon;
		// attaching body to world and shape to body
		body = world->CreateBody(&bodydef);
		body->CreateFixture(&fixture);
		body->SetUserData(agentD);
	}
}
