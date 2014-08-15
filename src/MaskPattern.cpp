//
//  MaskPattern.cpp
//  ofPatternGenerator
//
//  Created by Jesse Scott on 2014-08-14.
//
//

#include "MaskPattern.h"


void MaskPattern::setup(int num) {
    switch(num) {
        case 0:

        break;
        
        case 1:
            ofNoFill();
            ofSetCircleResolution(48);
ofSetLineWidth(5);
        break;
        
        case 2:
            ofNoFill();
ofSetLineWidth(5);
        break;
            
        case 3:
            ofNoFill();
ofSetLineWidth(5);
        break;

        case 4:
            ofFill();
ofSetLineWidth(5);
        break;
            
        case 5:
            ofFill();
ofSetLineWidth(5);
        break;
            
        case 6:
            ofNoFill();
ofSetLineWidth(5);
        break;

        case 7:
            ofNoFill();
            radius = 0.0;
ofSetLineWidth(5);
        break;
    }
}

void MaskPattern::update(int num) {
    // Global Settings
    //ofSetLineWidth(lineWidth);
    
    
    
    // Draw Modes
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
            }
            offset += 2;
            
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
            }
            break;
        }
            
        // RECTANGLES
        case 6:
        {
            if (offset % 150 == 0) {
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
            
            for (int i = 0; i < numOfShapes; i++) {
                float angle7 = ofGetElapsedTimef() * 3.6;
                float x7 = w/2 + radius * cos(angle7) * i;
                float y7 = h/2 + radius * sin(angle7) * i;
                ofCircle(x7, y7, radius * i);
            }
            
            radius = radius + 0.1;
            if(radius > 75.0) radius = 0.0;
            
            break;
        }
            
    }
}

/*
 
 UPDATERS
 
 */

void MaskPattern::updateWidth(int _lineWidth) {
    //lineWidth = _lineWidth;
}

void MaskPattern::updateNumber(int _numShapes) {
    //numOfShapes = _numShapes;
}

void MaskPattern::updateAngle(int _angle) {
    //angle = _angle;
}
void MaskPattern::updateSpeed(int _speed) {
    //speed = _speed;
}


/*
 
 Overridden Circle Method
 
 */

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