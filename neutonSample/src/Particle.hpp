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
        float G;
    public :
        Particle();
        void update();
        void draw(int alpha);
        void bounceOffWalls();
        void throughWalls();
        void addForce(ofVec2f force);
        void attract(ofVec2f center, float _mass, float min, float max);
    
};
#endif /* Particle_hpp */
