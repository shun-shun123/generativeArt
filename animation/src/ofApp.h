#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define BALL_NUM 1000
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
		
    ofVec2f pos[BALL_NUM];
    ofVec2f vel[BALL_NUM];
    float origin[BALL_NUM];
    float diamiter[BALL_NUM];
    float hue[BALL_NUM];
    float adjuster[BALL_NUM];
    
    ofxIntSlider alpha;
    ofxIntSlider ballNum;
    ofxFloatSlider diamiterRate;
    ofxFloatSlider hueRate;
    ofxPanel gui;
    
    int rotateDirection = -1; // 0->x 1->y 2->z -1->stop
    int xDegree = 0;
    int yDegree = 0;
    int zDegree = 0;
};
