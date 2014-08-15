#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableSmoothing();
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    
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
    lineWidth = 5;
    
    pattern.setup(currentPattern);
    //pattern.updateWidth(lineWidth);
}

//--------------------------------------------------------------
void ofApp::update(){
    drawingFbo.begin();
        ofClear(255,255,255, 0);
        ofBackground(0,0,0);
        ofSetColor(255);
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
//    lineWidth = ofClamp(lineWidth, 5, 45);
//    if(key == 357) { // UP
//        pattern.updateWidth(lineWidth += 5);
//    }
//    if(key == 359) { // DOWN
//        pattern.updateWidth(lineWidth -= 5);
//    }
}

void ofApp::mousePressed(int x, int y, int button) {
    //pattern.updateNumber(ofRandom(1, 5));
}

//--------------------------------------------------------------

void ofApp::setSettings(int num) {
    switch (num) {
        case 1: // CIRCLES
        {
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 2: // SQUARES
        {
            offset = 0;
            density = 100;
            numOfShapes = 8;
            break;
        }
        case 3: // TRIANGLES
        {
            offset = 0;
            density = 100;
            numOfShapes = 8;
            break;
        }
        case 4: // DOTS
        {
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 5: // LINES
        {
            offset = 0;
            density = 100;
            numOfShapes = 4;
            break;
        }
        case 6: // RECTANGLES
        {
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 7:
        {
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
        case 8:
        {
            offset = 0;
            density = 100;
            numOfShapes = 7;
            break;
        }
    }
    
    pattern.setup(currentPattern);
}


