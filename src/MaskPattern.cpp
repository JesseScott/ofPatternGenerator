//
//  MaskPattern.cpp
//  ofPatternGenerator
//
//  Created by Jesse Scott on 2014-08-14.
//
//

#include "MaskPattern.h"


void MaskPattern::setup(int num, int _angle, int _speed, int _offset, int _density, int _numOfShapes) {
    
    offset = _offset;
    density = _density;
    numOfShapes = _numOfShapes;
    
    switch(num) {
            case 0:

            break;
            
            case 1:
                ofNoFill();
                ofSetColor(255);
                ofSetCircleResolution(48);

            break;
            
            case 2:
                ofNoFill();
                ofSetColor(255);
                ofSetLineWidth(25);

            break;
            
        case 3:
            ofNoFill();
            ofSetColor(255);
            ofSetLineWidth(10);

        break;

        case 4:
            ofFill();
            ofSetColor(255);
            ofSetLineWidth(10);

        break;
            
        case 5:
            ofFill();
            ofSetColor(255);
            ofSetLineWidth(10);

        break;
            
        case 6:
            ofNoFill();
            ofSetColor(255);
            ofSetLineWidth(5);

        break;

        case 7:
            ofNoFill();
            ofSetColor(255);
            ofSetLineWidth(5);
            
        break;
    }
    
}

void MaskPattern::update(int num) {
    switch(num) {
        // DEFAULT
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
       
            for (int i = 0; i < numOfShapes; i++) {
                ofSetRectMode(OF_RECTMODE_CORNER);
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

            for (int i = 0; i < numOfShapes; i++) {
                ofTriangle(w/2 + 2, 0, w/2 - 2, h,  i * density + offset, h/2);
            }
            break;
        }
           
        // DOTS
        case 4:
        {
            if (offset % 200 == 0) {
                offset = 20;
            }
            offset += 2;

            if(ofGetFrameNum() % int(ofGetFrameRate()) == 0) {
                for (int i = 0; i < numOfShapes; i++) {
                    ofCircle(ofRandom(0, w), ofRandom(0, h), ofRandom(offset/2, offset));
                }
            }
            break;
        }
            
        // LINES
        case 5:
        {
            if (offset % 200 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            
            for (int i = 0; i < numOfShapes; i++) {
                float flow = ofMap(sin(ofGetElapsedTimef()), -0.1 * numOfShapes, 0.1 * numOfShapes, 0, w);
                ofLine(flow * i, h/2, flow * i, flow);
                ofLine(w-flow * i, h/2, w-flow * i, flow);
                //float flow2 = ofMap(sin(ofGetElapsedTimef()/2), -0.5, 0.5, w/4, 3*(w/4));
                //ofLine(flow2, h/2, flow2, flow2);
                //ofLine(w-flow2, h/2, w-flow2, flow2);
            }
            break;
        }
            
        // RECTANGLES
        case 6:
        {
            if (offset % 200 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            
            for (int i = 0; i < numOfShapes; i++) {
                    ofSetRectMode(OF_RECTMODE_CENTER);
                    ofRect(w/2, h/2, i * offset, i * (offset/4));
            }
            break;
        }
            
        // RECTANGLES
        case 7:
        {
            if (offset % 200 == 0) {
                offset = 0;
                //density--;
            }
            offset += 2;
            
            for (int i = 0; i < numOfShapes; i++) {
                ofSetRectMode(OF_RECTMODE_CENTER);
                ofRect(w/2, h/2, i * offset, i * (offset/4));
            }
            break;
        }
            
    }
}


void MaskPattern::circleStroke(int x, int y, int rad, int stroke) {
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