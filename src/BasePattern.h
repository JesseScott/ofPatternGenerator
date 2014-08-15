//
//  Pattern.h
//  patternGen
//
//  Created by Jesse Scott on 2014-08-14.
//
//

#ifndef __patternGen__BasePattern__
#define __patternGen__BasePattern__

#include "ofMain.h"

class BasePattern {
    public:

        BasePattern() {
            x = 0;
            y = 0;
            w = 704;
            h = 704;
        }
    
        ~BasePattern(){
            
        }
        
        void setup(int num);
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