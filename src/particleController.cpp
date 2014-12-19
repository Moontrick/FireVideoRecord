
#include "particleController.h"


void particleController::setup() {



}


void particleController::setEmitterLoc( ofVec3f _loc ) {

	origin = _loc;

}


void particleController::addParticle( int amt ) {

	for ( int i = 0; i < amt; i++ ) {

		Particle newParticle;
		newParticle.setup( origin );
		particles.push_back( newParticle );

	}

}


void particleController::update() {

	points.clear();
	sizes.clear();
	colors.clear();

	vector <Particle>::iterator p;
	for( p = particles.begin(); p != particles.end(); ) {

		if ( p->isDead() ) p = particles.erase( p );
		else {

			p->update();
			points.push_back( p->pLoc );
			sizes.push_back( ofVec3f( p->pRadius ) );
			colors.push_back( p->pColor );
			++p;

		}

	}

}


void particleController::draw() {

	vector <Particle>::iterator p;
	for( p = particles.begin(); p != particles.end(); ++p ) {

		p->draw();

	}

}


ofVec3f * particleController::getPointsReference() {

	return &points[0];

}


ofVec3f * particleController::getSizeReference() {

	return &sizes[0];

}


ofFloatColor * particleController::getColorReference() {

	return &colors[0];

}


int particleController::getNumPoints() {

	return (int)points.size();

}
