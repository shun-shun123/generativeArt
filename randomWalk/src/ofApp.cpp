#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    // initialize
    for (int i = 0; i < NUM; i++) {
        pos[i] = ofVec2f(ofRandomWidth(), ofRandomHeight());
        colors[i] = ofFloatColor(1.0, 1.0, 1.0, 0.5);
    }
    vbo.setVertexData(pos, NUM, GL_DYNAMIC_DRAW);
    vbo.setColorData(colors, NUM, GL_DYNAMIC_DRAW);
    // gui setup
    gui.setup();
    gui.add(ballNum.setup("ballNum", NUM, 0, NUM));
}

//--------------------------------------------------------------
void ofApp::update(){
    // update positions
    for (int i = 0; i < ballNum; i++) {
        pos[i] += ofVec2f(ofRandom(-3, 3), ofRandom(-3, 3));
        if (pos[i].x < 0) {
            pos[i].x = ofGetWidth();
        } else if (pos[i].x > ofGetWidth()) {
            pos[i].x = 0;
        } else if (pos[i].y < 0) {
            pos[i].y = ofGetHeight();
        } else if (pos[i].y > ofGetHeight()) {
            pos[i].y = 0;
        }
    }
    vbo.updateVertexData(pos, NUM);
    cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(0, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    vbo.draw(GL_POINTS, 0, ballNum);
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
