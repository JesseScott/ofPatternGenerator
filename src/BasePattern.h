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
            fbo.allocate(w, h, GL_RGBA);
        }
    
        ~BasePattern(){
            
        }
        
        void setup(int num);
        void update(int num);
        void draw();
        
        int x, y, w, h;
        int angle;
        int speed;
        int offset;
        int density;
    
        ofFbo fbo;
    
};

#endif /* defined(__patternGen__Pattern__) */