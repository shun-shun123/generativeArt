#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    init();
    acceleration = force * mass;
}

//--------------------------------------------------------------
void ofApp::update(){
    velocity += acceleration;
    location += velocity;
    if (location.x < 0 || location.x > ofGetWidth()) {
        velocity.x *= -1;
    }
    if (location.y < 0 || location.y > ofGetHeight()) {
        velocity.y *= -1;
    }
    acceleration = ofVec2f(0, 0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    fade(bgAlpha);
    ofSetColor(255, 60);
    ofDrawCircle(location, 20);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::init() {
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    gui.setup();
    gui.add(mass.setup("mass", 1.0, 0.1, 3.0));
    gui.add(bgAlpha.setup("bgAlpha", 10, 1, 100));
}

//--------------------------------------------------------------
void ofApp::fade(int alpha) {
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(0, alpha);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
}
