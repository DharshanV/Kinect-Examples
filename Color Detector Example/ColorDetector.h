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

	bool redFilter;
	bool greenFilter;
	bool blueFilter;

	void allocate();
	void applyRedFilter();
	void applyGreenFilter();
	void applyBlueFilter();
	void updateFilters();
};