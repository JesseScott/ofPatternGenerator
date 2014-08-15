#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableSmoothing();

    currentPattern = 0;
    
    pattern.setup(currentPattern);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    pattern.update(currentPattern);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    pattern.draw();
    
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << "key is " << key << endl;
    if (key > 48 && key < 57) {
        currentPattern = key - 48;
    }
    cout << "pattern is " << currentPattern << endl;
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
