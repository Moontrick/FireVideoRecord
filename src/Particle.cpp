
#include "Particle.h"


void Particle::setup( ofVec3f _loc ) {

	pLoc = _loc;
	pAcc.set( 0, 0.05f, 0 );
	pVel.set( ofRandom( -1, 1 ), ofRandom( -2, 0 ), 0 );
	pRadius = ofRandom( 5, 100 );
	pLifespan = 200;
    pAge = 0;
    
    r = (float)(255 / 255);
    g = (float)(255 * 0.4);
    b = (float)(255 * 0.2);
    a = (float)(pLifespan / 255);
	pColor = ofFloatColor( r, g, b, a ); //TODO:: add alpha channel

}


void Particle::update() {

	pVel += pAcc;
	pLoc += pVel;
	pAcc += ofVec3f( 0, 0.001, 0 );
	pLifespan -= 1.0f;
    pAge += 1.0f;

    r = ofMap( pLifespan, 0, 200, 0, 1, true );
    g = 0.4;
    b = ofMap( pAge, 0, 200, 0, 1, true );
	a = ofMap( pLifespan, 0, 255, 0, 1, true ); // mapped between 0 and 1 for color
	pColor = ofFloatColor( r, g, b, a );

}


void Particle::draw() {

	ofSetColor( 255, 128, 0, pLifespan );
	ofCircle( pLoc, pRadius );

}


bool Particle::isDead() {

	if ( pLifespan < 0.0f ) return true;
	else return false;

}