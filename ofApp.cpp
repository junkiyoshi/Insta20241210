#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofNoFill();
	ofSetLineWidth(1.5);
	
	ofEnableDepthTest();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 1.44);

	for (int deg = 0; deg < 180; deg += 15) {
		
		for (int i = 0; i < 5; i++) {

			auto noise_value = ofNoise(cos(deg * DEG_TO_RAD) * 0.5, sin(deg * DEG_TO_RAD) * 0.5, ofGetFrameNum() * 0.005 + i * 0.003);
	
			auto rotate = 0;
			if ((noise_value >= 0.4 && noise_value <= 0.6)) {

				rotate = ofMap(noise_value, 0.4, 0.6, 0, 360);
			}

			ofPushMatrix();

			ofRotateZ(deg);

			ofFill();
			ofDrawRectangle(glm::vec2(0, 250), 8, 8);
			ofDrawRectangle(glm::vec2(0, -250), 8, 8);

			ofRotateX(rotate);

			ofNoFill();
			ofSetColor(ofMap(i, 0, 10, 39, 39));
			ofDrawRectangle(glm::vec2(0, 250), ofMap(i, 0, 5, 10, 50), ofMap(i, 0, 5, 10, 50));
			ofDrawRectangle(glm::vec2(0, -250), ofMap(i, 0, 5, 10, 50), ofMap(i, 0, 5, 10, 50));

			ofPopMatrix();
		}
	}

	this->cam.end();

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}