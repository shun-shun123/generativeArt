#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void init();
    void fade(int alpha);
		
    ofVec2f force = ofVec2f(3.0, 2.0);
    ofVec2f acceleration;
    ofVec2f location = ofVec2f(0.0, 0.0);
    ofVec2f velocity = ofVec2f(0.0, 0.0);
    ofVec2f friction = ofVec2f(0.02, 0.02);
    ofVec2f direction;
    ofxFloatSlider mass;
    ofxIntSlider bgAlpha;
    ofxPanel gui;
};
