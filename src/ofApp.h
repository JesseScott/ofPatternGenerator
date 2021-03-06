#pragma once

#include "ofMain.h"
#include "MaskPattern.h"

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
        void mousePressed(int x, int y, int button);

        void setSettings(int num);
    
        int currentPattern;
        MaskPattern pattern;
        ofFbo drawingFbo;
    
        int angle;
        int speed;
        int offset;
        int density;
        int numOfShapes;
        int lineWidth;
};
