#pragma once

#include "ofMain.h"
#include "particleController.h"
#include "ofxVideoRecorder.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void uploadVboData();
    void keyReleased( int key );
    void exit();
    
    particleController controller;
    ofTexture          texture;
    
    ofVbo              vbo;
    
    ofShader           shader;
    
    ofxVideoRecorder   recorder;
    
    bool               bRecording;
    int                sampleRate, channels;
    string             fileName, fileExt;
    
    ofFbo              recordFbo;
    ofPixels           recordPixels;
    
};
