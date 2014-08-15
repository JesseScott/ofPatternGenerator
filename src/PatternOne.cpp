//
//  PatternOne.cpp
//  patternGen
//
//  Created by Jesse Scott on 2014-08-14.
//
//

#include "PatternOne.h"


int offset = 0;
int density = 100;

void PatternOne::setup() {
    x = 0;
    y = 0;
    w = 704;
    h = 704;
    
    fbo.allocate(w, h, GL_RGBA);
    fbo.begin();
        ofClear(255,255,255, 0);
        ofNoFill();
        ofEnableSmoothing();
        ofSetColor(255);
        ofSetLineWidth(10);
    fbo.end();
    
}

void PatternOne::update() {
    fbo.begin();
        ofClear(128, 128, 128, 255);

        if (offset%100 == 0) {
            offset = 0;
            //density--;
        }
        offset+=2;
        ofBackground(0,0,0);
        for (int i = 0; i < 7; i++) {
            ofCircle(w/2, h/2, i * density + offset, i * density + offset);
        }
    
    fbo.end();
}

void PatternOne::draw() {
    ofSetColor(255);
    fbo.draw(x, y, w, h);
}