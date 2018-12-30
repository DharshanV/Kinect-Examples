#pragma once
#include "ofxKinect.h"
#include "ofxOpenCv.h"
class ColorDetector {
public:
	ColorDetector(ofxKinect* kinect = NULL, bool redFilter = true,
		bool greenFilter = false, bool blueFilter = false);
	void update();
	void drawColor(int x, int y, int w, int h);
	void drawRects(int x, int y, int w, int h);
	int getBoxCount() {
		return finder.blobs.size();
	}
	const ofRectangle& box(int i) {
		return finder.blobs.at(i).boundingRect;
	}

	float getScaleX() {
		return scaleX;
	}

	float getScaleY() {
		return scaleY;
	}

	int redThreshold = 50;
	int greenThreshold = 1;
	int blueThreshold = 25;
	int numOfObjects = 1;
	int minFindArea = 800;
private:
	int width, height, maxArea;
	ofxKinect* kinect;

	ofxCvColorImage colorImage;

	ofxCvGrayscaleImage redChannel;
	ofxCvGrayscaleImage greenChannel;
	ofxCvGrayscaleImage blueChannel;

	ofxCvGrayscaleImage redFiltered;
	ofxCvGrayscaleImage greenFiltered;
	ofxCvGrayscaleImage blueFiltered;

	ofxCvGrayscaleImage filtered;

	ofxCvContourFinder finder;

	float scaleX = 1.0f;
	float scaleY = 1.0f;

	bool redFilter;
	bool greenFilter;
	bool blueFilter;

	void allocate();
	void applyRedFilter();
	void applyGreenFilter();
	void applyBlueFilter();
	void updateFilters();
};