#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	kinect.setRegistration(true);
	kinect.init();
	kinect.open();

	colorDetector = new ColorDetector(&kinect,true,false,true);
}

//--------------------------------------------------------------
void ofApp::update(){
	kinect.update();
	if (kinect.isFrameNew()) {
		colorDetector->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	easyCam.begin();
	drawPointCloud();
	easyCam.end();

	ofSetColor(255);
	colorDetector->drawColor(0, 0, WIDTH/3, HEIGHT/3);
	colorDetector->drawRects(0, 0, WIDTH/3, HEIGHT/3);
}

void ofApp::drawPointCloud() {
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_POINTS);

	int steps = numOfDots;
	for (int i = 0; i < colorDetector->getBoxCount(); i++) {
		const ofRectangle* box = &colorDetector->box(i);
		for (int j = box->x; j < box->width + box->x; j += steps) {
			for (int k = box->y; k < box->height + box->y; k += steps) {
				mesh.addColor(kinect.getColorAt(j, k));
				mesh.addVertex(kinect.getWorldCoordinateAt(j, k));
			}
		}
	}

	glViewport(0, 0, WIDTH, HEIGHT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(3);
	ofPushMatrix();
	ofScale(-1, -1, -1);
	ofTranslate(0, 0, -1000);
	glEnable(GL_DEPTH_TEST);
	mesh.drawVertices();
	glDisable(GL_DEPTH_TEST);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case '1':
		colorDetector->redThreshold -= 5;
		cout << "Red thres: " << colorDetector->redThreshold << endl;
		break;
	case '2':
		colorDetector->redThreshold += 5;
		cout << "Red thres: " << colorDetector->redThreshold << endl;
		break;
	case '3':
		colorDetector->greenThreshold -= 1;
		cout << "Green thres: " << colorDetector->greenThreshold << endl;
		break;
	case '4':
		colorDetector->greenThreshold += 1;
		cout << "Green thres: " << colorDetector->greenThreshold << endl;
		break;
	case '5':
		colorDetector->blueThreshold -= 5;
		cout << "Blue thres: " << colorDetector->blueThreshold << endl;
		break;
	case '6':
		colorDetector->blueThreshold += 5;
		cout << "Blue thres: " << colorDetector->blueThreshold << endl;
		break;
	case '=':
		colorDetector->minFindArea += 100;
		cout << "Min area: " << colorDetector->minFindArea << endl;
		break;
	case '-':
		colorDetector->minFindArea -= 100;
		cout << "Min area: " << colorDetector->minFindArea << endl;
		break;
	case 'o':
		colorDetector->numOfObjects++;
		cout << "Num of objects: " << colorDetector->numOfObjects << endl;
		break;
	case 'p':
		colorDetector->numOfObjects--;
		cout << "Num of objects: " << colorDetector->numOfObjects << endl;
		break;
	case ',':
		numOfDots++;
		break;
	case '.':
		numOfDots--;
		break;
	default:
		break;
	}
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
