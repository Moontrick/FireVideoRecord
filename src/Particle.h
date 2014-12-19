
#pragma once

#include "ofMain.h"
#include "ofMath.h"

class Particle {

	public:

		void setup( ofVec3f _loc );
		void update();
		void draw();
		bool isDead();

		ofVec3f pLoc, pVel, pAcc;

		float pLifespan, pAge, pRadius;

        float r, g, b, a;
		ofFloatColor pColor;

};