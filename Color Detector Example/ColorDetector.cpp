#include "ColorDetector.h"

ColorDetector::ColorDetector(ofxKinect* kinect, bool redFilter,
	bool greenFilter, bool blueFilter) {
	this->kinect = kinect;
	this->redFilter = redFilter;
	this->greenFilter = greenFilter;
	this->blueFilter = blueFilter;
	this->width = kinect->width;
	this->height = kinect->height;
	this->maxArea = width * height;
	allocate();
}

void ColorDetector::allocate() {
	colorImage.allocate(width, height);

	filtered.allocate(width, height);

	redFiltered.allocate(width, height);
	greenFiltered.allocate(width, height);
	blueFiltered.allocate(width, height);
	
	redChannel.allocate(width, height);
	greenChannel.allocate(width, height);
	blueChannel.allocate(width, height);
}

void ColorDetector::update() {
	colorImage.setFromPixels(kinect->getPixels().getData(),
		width, height);
	colorImage.mirror(false, true);

	if (redFilter) {
		applyRedFilter();
	}
	if (greenFilter) {
		applyGreenFilter();
	}
	if (blueFilter) {
		applyBlueFilter();
	}
	updateFilters();
}

void ColorDetector::updateFilters() {
	for (int i = 0; i < maxArea; i++) {
		unsigned char* pixel = &filtered.getPixels()[i];

		*pixel = 0;
		if (redFilter) {
			*pixel += ofInRange(redFiltered.getPixels()[i], 0, redThreshold) ? 0 : 255;
		}
		if (greenFilter) {
			*pixel += ofInRange(greenFiltered.getPixels()[i], 0, greenThreshold) ? 0 : 255;
		}
		if (blueFilter) {
			*pixel += ofInRange(blueFiltered.getPixels()[i], 0, blueThreshold) ? 0 : 255;
		}

		if (*pixel > 255) {
			*pixel = 255;
		}
	}
	filtered.flagImageChanged();
	finder.findContours(filtered, minFindArea, maxArea, numOfObjects, true);
}

void ColorDetector::applyRedFilter() {
	colorImage.convertToGrayscalePlanarImages(redChannel,
		greenChannel,
		blueChannel);
	greenChannel += blueChannel;
	redChannel -= greenChannel;
	redFiltered = redChannel;
}

void ColorDetector::applyGreenFilter() {
	colorImage.convertToGrayscalePlanarImages(redChannel,
		greenChannel,
		blueChannel);
	redChannel += blueChannel;
	greenChannel -= redChannel;
	greenFiltered = greenChannel;
}

void ColorDetector::applyBlueFilter() {
	colorImage.convertToGrayscalePlanarImages(redChannel,
		greenChannel,
		blueChannel);
	redChannel += greenChannel;
	blueChannel -= redChannel;
	blueFiltered = blueChannel;
}

void ColorDetector::drawColor(int x, int y, int w, int h) {
	colorImage.draw(x, y, w, h);
}

void ColorDetector::drawRects(int x, int y, int w, int h) {
	const vector<ofxCvBlob>* blobs = &finder.blobs;
	if (blobs->size() == 0) {
		return;
	}
	float scalex = 0.0f;
	float scaley = 0.0f;
	scalex = (float)w / width;
	scaley = (float)h / height;

	ofSetColor(255,255,255);
	ofNoFill();
	for (int i = 0; i < (int)blobs->size(); i++) {
		ofRectangle rect = blobs->at(i).boundingRect;
		rect.x *= scalex;
		rect.y *= scaley;
		rect.width *= scalex;
		rect.height *= scaley;
		ofDrawRectangle(rect);
	}
}