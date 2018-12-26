#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	kinect.setRegistration(true);

	kinect.init();
	kinect.open();

	ofSetFrameRate(60);

	angle = 30;
	kinect.setCameraTiltAngle(angle);

	grayImage.allocate(kinect.width, kinect.height);
	colorImage.allocate(kinect.width, kinect.height);

	nearDistance = 0;
	maxDistance = 1000;

	numOfDots = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
	kinect.update();
	colorImage.setFromPixels(kinect.getPixels().getData(), kinect.width, kinect.height);
	grayImage.setFromColorImage(colorImage);
	grayImage.flagImageChanged();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	kinect.draw(width/2, height/2, width/2, height/2);
	kinect.drawDepth(width / 2, 0, width / 2, height/2);
	grayImage.draw(0, 0, width / 2, height / 2);


	easyCam.begin();
	drawPointCloud();
	easyCam.end();

	stringstream fpsString;
	fpsString << ofGetFrameRate() << endl;
	ofDrawBitmapString(fpsString.str(), 10, 10);
}

void ofApp::drawPointCloud() {
	int easyCamW = 640;
	int easyCamH = 480;
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_POINTS);

	int steps = numOfDots;

	for (int i = 0; i < easyCamW; i += steps) {
		for (int j = 0; j < easyCamH; j += steps) {
			float d = kinect.getDistanceAt(i, j);
			if (d > 0 && d < maxDistance) {
				mesh.addColor(kinect.getColorAt(i,j));
				mesh.addVertex(kinect.getWorldCoordinateAt(i,j));
			}
		}
	}
	glViewport(0,0, width / 2, height / 2);
	glClearColor(255,0,0, 1.0f);
	glPointSize(3);
	ofPushMatrix();
	// the projected points are 'upside down' and 'backwards' 
	ofScale(1, -1, -1);
	ofTranslate(0,0, -1000); // center the points a bit
	glEnable(GL_DEPTH_TEST);
	mesh.drawVertices();
	glDisable(GL_DEPTH_TEST);
	ofPopMatrix();
}

void ofApp::exit() {
	kinect.setCameraTiltAngle(0);
	kinect.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'w':
		maxDistance+=50;
		break;
	case 's':
		maxDistance-=50;
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key)
	{
	case OF_KEY_UP:
		angle++;
		if (angle > 30) angle = 30;
		kinect.setCameraTiltAngle(angle);
		break;
	case OF_KEY_DOWN:
		angle--;
		if (angle < -30) angle = -30;
		kinect.setCameraTiltAngle(angle);
		break;
	case '+':
	case '=':
		numOfDots += 1;
		break;
	case '-':
	case '_':
		numOfDots -= 1;
		if (numOfDots < 5) {
			numOfDots = 5;
		}
		break;
	default:
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
