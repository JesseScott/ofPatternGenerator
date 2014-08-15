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
    pattern.setup(currentPattern);

}

//--------------------------------------------------------------
void ofApp::update(){
    drawingFbo.begin();
        pattern.update(currentPattern);
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
    }
    pattern.setup(currentPattern);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
