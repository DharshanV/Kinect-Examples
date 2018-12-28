#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	unsigned int WIDTH = 600;
	unsigned int HEIGHT = 600;
	ofSetupOpenGL(WIDTH, HEIGHT,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp(WIDTH, HEIGHT));

}
