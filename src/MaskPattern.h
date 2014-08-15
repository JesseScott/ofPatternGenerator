//
//  MaskPattern.h
//  ofPatternGenerator
//
//  Created by Jesse Scott on 2014-08-14.
//
//

#ifndef __patternGen__MaskPattern__
#define __patternGen__MaskPattern__

#include "ofMain.h"

class MaskPattern {
    public:

        MaskPattern() {
            x = 0;
            y = 0;
            w = 704;
            h = 704;
        }
    
        ~MaskPattern(){
            
        }
        
        void setup(int num);
        void update(int num);
    
        void updateWidth(int _lineWidth);
        void updateNumber(int _numShapes);
        void updateAngle(int _angle);
        void updateSpeed(int _speed);
    
        void circleStroke(int x, int y, int rad, int stroke);
        
        int x, y, w, h;
    
        float radius;
    
        int angle;
        int speed;
        int offset;
        int density;
        int lineWidth;
        int numOfShapes;
    
};

#endif /* defined(__patternGen__Pattern__) */