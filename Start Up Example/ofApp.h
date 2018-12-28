#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		ofApp(unsigned int width,unsigned int height) {
			this->width = width;
			this->height = height;
		}
		void setup();
		void update();
		void draw();
		void exit();

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
	ofxCvBlob blob;
	ofxCvColorImage colorImage;
	ofxCvGrayscaleImage grayImage; // grayscale depth image
	ofEasyCam easyCam;
	float angle;
	unsigned int width;
	unsigned int height;
	int nearDistance;
	int maxDistance;
	int numOfDots;

	void drawPointCloud();
};
