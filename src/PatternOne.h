//
//  PatternOne.h
//  patternGen
//
//  Created by Jesse Scott on 2014-08-14.
//
//

#ifndef __patternGen__PatternOne__
#define __patternGen__PatternOne__

#include "ofMain.h"
#include "BasePattern.h"

class PatternOne : public BasePattern  {
public:
    
    PatternOne() {
        
    }
    
    ~PatternOne(){
        
    }
    
    void setup();
    void update();
    void draw();
    
    int x, y, w, h;
    int angle;
    int speed;
    
    ofFbo fbo;
    
};


#endif /* defined(__patternGen__PatternOne__) */
