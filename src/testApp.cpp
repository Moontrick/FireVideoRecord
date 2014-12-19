#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    sampleRate = 44100;
    channels   = 2;
    
    ofSetFrameRate( 60 );
    
    fileName   = "testMovie";
    fileExt    = ".mov";
    
    recorder.setVideoCodec( "mpeg4" );
    recorder.setVideoBitrate( "800k" );
    //recorder.setupCustomOutput(ofGetWidth(), ofGetHeight(), 30.0f, sampleRate, channels, fileName );
    
    bRecording  = false;
    
	ofBackground( 0 );
    
	ofDisableArbTex();
	ofLoadImage( texture, "particle.png" );
    
	shader.load( "shaders/shader" );
    
}

//--------------------------------------------------------------
void testApp::update(){
    
	ofVec3f mouseLoc = ofVec3f( ofGetMouseX(), ofGetMouseY(), 0 );
	controller.setEmitterLoc( mouseLoc );
	controller.addParticle( 15 );
    
	controller.update();
    
	uploadVboData();
    
    ofImage screen;
    
    if ( bRecording ) {
        screen.grabScreen( 0, 0, ofGetWidth(), ofGetHeight() );
        recorder.addFrame( screen.getPixelsRef() );
    }

    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofEnableBlendMode( OF_BLENDMODE_ADD );
	ofEnablePointSprites();
    
	shader.begin();
    
	texture.bind();
	vbo.draw( GL_POINTS, 0, controller.getNumPoints() );
	texture.unbind();
    
	shader.end();
    
	ofDisablePointSprites();
	ofDisableBlendMode();
    
    stringstream ss;
    ss << "video queue size: " << recorder.getVideoQueueSize() << endl
    // << "audio queue size: " << recorder.getAudioQueueSize() << endl
    << "FPS: " << ofGetFrameRate() << endl
    << (bRecording?"pause":"start") << " recording: r" << endl
    << (bRecording?"close current video file: c":"") << endl;
    
    ofEnableAlphaBlending();
    ofSetColor( 0, 0, 0, 100 );
    ofRect( 0, 0, 260, 75 );
    ofSetColor( 255 );
    ofDrawBitmapString( ss.str(), 15, 15 );
    ofDisableAlphaBlending();
    
}


void testApp::uploadVboData() {
    
	// Get all the data the VBO needs from the particle controller
	int total                 = controller.getNumPoints();
	ofVec3f * pointsRef       = controller.getPointsReference();
	ofVec3f * sizesRef        = controller.getSizeReference();
	ofFloatColor * colorsRef  = controller.getColorReference();
    
	// Upload all of the data to the VBO
	vbo.setVertexData( pointsRef, total, GL_STATIC_DRAW );
	vbo.setColorData( colorsRef, total, GL_STATIC_DRAW );
	vbo.setNormalData( sizesRef, total, GL_STATIC_DRAW );

}


void testApp::keyReleased( int key ) {
    
    if ( key == 'r' ) {
        
        bRecording = !bRecording;
        if ( bRecording && !recorder.isInitialized() ) {
            
            recorder.setup(fileName+ofGetTimestampString()+fileExt, ofGetWidth(), ofGetHeight(), 60);
            
        }
        
    }
    
    if ( key == 'c' ) {
        
        bRecording = false;
        recorder.close();
        
    }
    
}


void testApp::exit() {
    
    recorder.close();
    
}
























