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
	ofSetColor(255);
	colorDetector->drawColor(0, 0, WIDTH, HEIGHT);
	colorDetector->drawRects(0, 0, WIDTH, HEIGHT);
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
