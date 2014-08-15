#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableSmoothing();
    ofSetFrameRate(30);
    
    drawingFbo.allocate(704, 704, GL_RGBA);
    drawingFbo.begin();
        ofClear(255,255,255, 0);
        ofEnableSmoothing();
    drawingFbo.end();

    currentPattern = 0;
    angle = 0;
    speed = 0;
    offset = 0;
    density = 100;
    numOfShapes = 7;
    pattern.setup(currentPattern, angle, speed, offset, density, numOfShapes);

}

//--------------------------------------------------------------
void ofApp::update(){
    drawingFbo.begin();
        ofClear(255,255,255, 0);
        ofBackground(0,0,0);
        ofPushMatrix(); ofPushStyle();
            pattern.update(currentPattern);
        ofPopMatrix(); ofPopStyle();
    drawingFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawingFbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key > 48 && key < 57) {
        currentPattern = key - 48;
        setSettings(currentPattern);
    }
}

//--------------------------------------------------------------

void ofApp::setSettings(int num) {
    switch (num) {
        case 1: // CIRCLES
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 2: // SQUARES
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 8;
            break;
        }
        case 3: // TRIANGLES
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 8;
            break;
        }
        case 4: // DOTS
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 5: // LINES
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 4;
            break;
        }
        case 6: // RECTANGLES
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 7:
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 8:
        {
            angle = 0;
            speed = 0;
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
    }
    
    pattern.setup(currentPattern, angle, speed, offset, density, numOfShapes);
}


