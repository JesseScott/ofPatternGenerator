//
//  Pattern.cpp
//  patternGen
//
//  Created by Jesse Scott on 2014-08-14.
//
//

#include "BasePattern.h"


void BasePattern::setup(int num) {
    switch(num) {
            case 0:

            break;
            
            case 1:
                ofClear(255,255,255, 0);
                ofNoFill();
                ofSetColor(255);
                ofSetCircleResolution(48);
            
                offset = 0;
                density = 100;
                numOfShapes = 7;
            break;
            
            case 2:
                ofClear(255,255,255, 0);
                ofNoFill();
                ofSetColor(255);
                ofSetLineWidth(25);

                offset = 0;
                density = 100;
                numOfShapes = 8;
            break;
            
        case 3:
            ofClear(255,255,255, 0);
            ofNoFill();
            ofSetColor(255);
            ofSetLineWidth(10);
            
            offset = 0;
            density = 100;
            numOfShapes = 7;
        break;

        case 4:
            ofClear(255,255,255, 0);
            ofFill();
            ofSetColor(255);
            ofSetLineWidth(10);
            
            offset = 0;
            density = 100;
            numOfShapes = 7;
        break;
            
        case 5:
            ofClear(255,255,255, 0);
            ofFill();
            ofSetColor(255);
            ofSetLineWidth(10);
            
            offset = 0;
            density = 100;
            numOfShapes = 7;
        break;
    }
    
}

void BasePattern::update(int num) {
    switch(num) {
        case 0:
        {
            break;
        }
        // CIRCLES
        case 1:
        {
            if (offset % 100 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            ofBackground(0,0,0);
            for (int i = 0; i < numOfShapes; i++) {
                ofFill();
                //ofCircle(w/2, h/2, i * density + offset);
                circleStroke(w/2, h/2, i * density + offset, 25);
            }
            break;
        }
            
        // SQUARES
        case 2:
        {
            if (offset % 100 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            ofBackground(0,0,0);
            for (int i = 0; i < numOfShapes; i++) {
                ofRect(w/2, 0-20, i * density + offset, i * density + offset);
                ofRect(w/2, 0-20, -i * density + offset, i * density - offset);
            }
            break;
        }

        // TRIANGLES
        case 3:
        {
            if (offset % 100 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            ofBackground(0,0,0);
            for (int i = 0; i < numOfShapes; i++) {
                ofTriangle(w/2, 0, w/2, h,  i * density + offset, h/2);
            }
            break;
        }
           
        // DOTS
        case 4:
        {
            if (offset % 100 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            ofBackground(0,0,0);
            int step = ofGetFrameNum() % int(ofGetFrameRate());
            if(step == 0) {
                for (int i = 0; i < numOfShapes; i++) {
                    ofCircle(ofRandom(0, w), ofRandom(0, h), ofRandom(offset/2, offset));
                }
            }
            break;
        }
            
        // DOTS
        case 5:
        {
            if (offset % 100 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            ofBackground(0,0,0);
            for (int i = 0; i < numOfShapes; i++) {
                float flow1 = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, w);
                ofLine(flow1, h/2, flow1, flow1);
                ofLine(w-flow1, h/2, w-flow1, flow1);
                float flow2 = ofMap(sin(ofGetElapsedTimef()/2), -0.5, 0.5, w/4, 3*(w/4));
                ofLine(flow2, h/2, flow2, flow2);
                ofLine(w-flow2, h/2, w-flow2, flow2);
            }
            break;
        }
    }
}


void BasePattern::circleStroke(int x, int y, int rad, int stroke) {
    ofBeginShape();
        int resolution = 22;
        float angle = 0;
        
        for( int i=0; i<resolution; i++ ){
            angle = i*2*PI/resolution;
            ofVertex(x + rad*sin(angle), y + rad*cos(angle));
        }
        
        ofNextContour(true);
        int rad2 = rad - stroke;
        
        for( int i=0; i<resolution; i++ ){
            angle = i*2*PI/resolution;
            ofVertex(x + rad2*sin(angle), y + rad2*cos(angle));
        }
	ofEndShape(true);
}