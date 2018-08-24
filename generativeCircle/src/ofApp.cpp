#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    
    middle = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    maxDist = sqrt(pow(ofGetWidth() / 2, 2) * pow(ofGetHeight() / 2, 2));
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < balls.size(); i++) {
        balls[i].alpha--;
        
        if (balls[i].alpha <= 0) {
            balls.erase(balls.begin() + i);
        }
    }
    ofVec2f pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
    int alpha = ofMap(middle.distance(pos), 0, 200, 255, 50);
    int size = ofMap(middle.distance(pos), 0, 200, 20, 5);
    Ball ball = Ball{pos, alpha, size};
    balls.push_back(ball);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 5);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for (int i = 0; i < balls.size(); i++) {
        ofSetColor(100, balls[i].alpha);
        ofDrawCircle(balls[i].pos, balls[i].size);
    }
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
