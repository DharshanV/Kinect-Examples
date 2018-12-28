#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "..\ColorDetector.h"
class ofApp : public ofBaseApp{

public:
	ofApp(int w, int h) {
		WIDTH = w;
		HEIGHT = h;
	}

	~ofApp() {
		if(colorDetector != NULL)
			delete colorDetector;
	}

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
private:
	ofxKinect kinect;
	ColorDetector* colorDetector;
	int WIDTH;
	int HEIGHT;
};
