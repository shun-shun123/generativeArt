#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    init();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) {
        particles[i].update();
        particles[i].bounceOffWalls();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fade(bgAlpha);
    for (int i = 0; i < NUM; i++) {
        particles[i].draw(alpha);
    }
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
    gui.add(alpha.setup("alpha", 50, 10, 100));
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
