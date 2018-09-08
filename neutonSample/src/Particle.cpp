//
//  Particle.cpp
//  neutonSample
//
//  Created by 斉藤俊介 on 2018/09/08.
//

#include "Particle.hpp"
Particle::Particle() {
    radius = 4.0;
    mass = 1.0;
    friction = ofVec2f(0.01, 0.01);
    float angle = ofRandom(TWO_PI);
    float length = ofRandom(20);
    float posX = cos(angle) * length;
    float posY = sin(angle) * length;
    location = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    velocity = ofVec2f(0.0, 0.0);
    acceleration = ofVec2f(posX, posY);
    gravity = ofVec2f(0.0, ofRandom(0.05, 0.2));
}

void Particle::update() {
    acceleration += gravity;
    velocity += acceleration;
    velocity *= (ofVec2f(1.0, 1.0) - friction);
    location += velocity;
    acceleration = ofVec2f(0.0, 0.0);
}

void Particle::draw(int alpha) {
    ofSetColor(255, alpha);
    ofDrawCircle(location, mass * radius * 2);
}

void Particle::bounceOffWalls() {
    if (location.x < 0) {
        location.x = 0;
        velocity.x *= -1;
    } else if (location.x > ofGetWidth()) {
        location.x = ofGetWidth();
        velocity.x *= -1;
    }
    if (location.y < 0) {
        location.y = 0;
        velocity.y *= -1;
    } else if (location.y > ofGetHeight()) {
        location.y = ofGetHeight();
        velocity.y *= -1;
    }
}

void Particle::throughWalls() {
    if (location.x < 0) {
        location.x = ofGetWidth();
    } else if (location.x > ofGetWidth()) {
        location.x = 0;
    }
    if (location.y < 0) {
        location.y = 0;
        velocity.y *= -1;
    } else if (location.y > ofGetHeight()) {
        location.y = ofGetHeight();
        velocity.y *= -1;
    }
}
