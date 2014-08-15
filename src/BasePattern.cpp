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
                fbo.begin();
                    ofClear(255,255,255, 0);
                fbo.end();
            break;
            
            case 1:
                fbo.begin();
                    ofClear(255,255,255, 0);
                    ofNoFill();
                    ofEnableSmoothing();
                    ofSetColor(255);
                    ofSetLineWidth(10);
                fbo.end();
                offset = 0;
                density = 100;
            break;
            
            case 2:
                fbo.begin();
                    ofClear(255,255,255, 0);
                    ofNoFill();
                    ofEnableSmoothing();
                    ofSetColor(255);
                    ofSetLineWidth(10);
                fbo.end();
                offset = 0;
                density = 100;
            break;
    }
    
}

void BasePattern::update(int num) {
    switch(num) {
        case 0:
            
            break;
            
        case 1:
            fbo.begin();
                ofClear(128, 128, 128, 255);
                if (offset%100 == 0) {
                    offset = 0;
                    //density--;
                }
                offset += 2;
                ofBackground(0,0,0);
                for (int i = 0; i < 7; i++) {
                    ofCircle(w/2, h/2, i * density + offset, i * density + offset);
                }
            fbo.end();
        break;
            
        case 2:
            fbo.begin();
                ofClear(128, 128, 128, 255);
                if (offset%100 == 0) {
                    offset = 0;
                    //density--;
                }
                offset += 2;
                ofBackground(0,0,0);
                for (int i = 0; i < 7; i++) {
                    ofRect(w/2-20, 0, i * density + offset, i * density + offset);
                    ofRect(w/2-20, 0, -i * density + offset, i * density - offset);
                }
            fbo.end();
        break;
    }
}

void BasePattern::draw() {
    ofSetColor(255);
    fbo.draw(x, y, w, h);
}