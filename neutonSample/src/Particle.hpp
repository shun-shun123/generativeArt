//
//  Particle.hpp
//  neutonSample
//
//  Created by 斉藤俊介 on 2018/09/08.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"


class Particle {
    private :
        ofVec2f location;
        ofVec2f velocity;
        ofVec2f acceleration;
        ofVec2f gravity;
        float mass;
        ofVec2f friction;
        float radius;
    public :
        Particle();
        void update();
        void draw(int alpha);
        void bounceOffWalls();
        void throughWalls();
    
};
#endif /* Particle_hpp */
