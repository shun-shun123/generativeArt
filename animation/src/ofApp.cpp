#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    // 初期設定
    for (int i = 0; i < BALL_NUM; i++) {
        pos[i] = ofVec2f(ofRandomWidth(), ofRandomHeight());
        vel[i] = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10));
        origin[i] = ofRandom(5, 50);
        hue[i] = 0;
        adjuster[i] = ofRandom(-PI, PI);
    }
    
    // GUI設定
    gui.setup();
    gui.add(alpha.setup("alpha", 100, 0, 255));
    gui.add(ballNum.setup("ballNum", BALL_NUM, 0, BALL_NUM));
    gui.add(diamiterRate.setup("diamiterRate", 0.1, 0, 0.3));
    gui.add(hueRate.setup("hueRate", 0.01, 0, 0.1));
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < ballNum; i++) {
        pos[i] += vel[i];
        if (pos[i].x < 0 || pos[i].x > ofGetWidth()) {
            vel[i].x *= -1;
        }
        if (pos[i].y < 0 || pos[i].y > ofGetHeight()) {
            vel[i].y *= -1;
        }
        diamiter[i] = origin[i] + sin(ofGetFrameNum() * diamiterRate) * 30;
        hue[i] = ofMap(sin(ofGetFrameNum() * hueRate + adjuster[i]) * 255, -255, 255, 0, 255);
    }
    switch (rotateDirection) {
        case 0:
            xDegree++;
            break;
        case 1:
            yDegree++;
            break;
        case 2:
            zDegree++;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < ballNum; i++) {
        ofPushMatrix();
        switch (rotateDirection) {
            case 0:
                ofTranslate(pos[i].x, pos[i].y);
                ofRotateX(xDegree);
                break;
            case 1:
                ofTranslate(pos[i].x, pos[i].y);
                ofRotateY(yDegree);
                break;
            case 2:
                ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
                ofRotateX(zDegree);
                ofRotateY(zDegree);
                break;
            default:
                ofTranslate(pos[i].x, pos[i].y);
                break;
        }
        ofSetColor(ofColor::fromHsb(hue[i], 255, 255, alpha));
        if (rotateDirection != 2) {
            ofDrawCircle(0, 0, diamiter[i]);
        } else {
            ofDrawCircle(pos[i].x - ofGetWidth() / 2, pos[i].y - ofGetHeight() / 2, diamiter[i]);
        }
        ofPopMatrix();
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case '0':
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            ofSetWindowTitle("OF_BLENDMODE_ADD");
            break;
        case '1':
            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
            ofSetWindowTitle("OF_BLENDMODE_ALPHA");
            break;
        case '2':
            ofEnableBlendMode(OF_BLENDMODE_SCREEN);
            ofSetWindowTitle("OF_BLENDMODE_SCREEN");
            break;
        case '3':
            ofEnableBlendMode(OF_BLENDMODE_DISABLED);
            ofSetWindowTitle("OF_BLENDMODE_DISABLED");
            break;
        case '4':
            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            ofSetWindowTitle("OF_BLENDMODE_MULTIPLY");
            break;
        case '5':
            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            ofSetWindowTitle("OF_BLENDMODE_SUBTRACT");
            break;
        case 'x':
            rotateDirection = 0;
            break;
        case 'y':
            rotateDirection = 1;
            break;
        case 'z':
            rotateDirection = 2;
            break;
        case 'r':
            rotateDirection = -1;
            break;
    }
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
