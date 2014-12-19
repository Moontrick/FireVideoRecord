
#pragma once

#include "ofMain.h"
#include "Particle.h"

class particleController {

	public:

		void setup();
		void update();
		void draw();
		void setEmitterLoc( ofVec3f _loc );
		void addParticle( int _amt );
		ofVec3f * getPointsReference();
		ofVec3f * getSizeReference();
		ofFloatColor * getColorReference();
		int      getNumPoints();

		//////////////////////////////////////////////////////////

		ofVec3f                      origin;
		vector <Particle>            particles;

		vector <ofVec3f>             points, sizes;
		vector <ofFloatColor>        colors;
		int                          totalPoints;

};