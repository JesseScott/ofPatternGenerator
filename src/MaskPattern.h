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
        
        void setup(int _num, int _angle, int _speed, int _offset, int _density, int _numOfShapes);
        void update(int num);
    
        void circleStroke(int x, int y, int rad, int stroke);
        
        int x, y, w, h;
        int angle;
        int speed;
        int offset;
        int density;
        int numOfShapes;
    
};

#endif /* defined(__patternGen__Pattern__) */