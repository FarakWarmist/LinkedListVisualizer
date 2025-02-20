#include "ofApp.h"
#include <cstdlib>
#include <ctime>

//--------------------------------------------------------------
void ofApp::setup(){
	circlesList.insertAtHead(10 + std::rand() % 91);
}

//--------------------------------------------------------------
void ofApp::update(){
	time += ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw(){
	Node* temp = circlesList.head;
	Node* prev = nullptr;
	index = 0;

	while (temp != nullptr)
	{
		float yOffset = sin(time * speed + index) * amplitude;
		float x = 100 + index * 200 + cameraOffset;
		float y = 200 + yOffset;

		ofSetColor(255);
		ofDrawCircle(x, y, temp->data);
		ofSetColor(0);
		ofDrawBitmapString(ofToString(temp->data), x - 5, y + 5);

		if (prev != nullptr)
		{
			ofSetColor(255);
			ofDrawLine((100 + (index - 1) * 200) + cameraOffset, 200 + sin(time * speed + (index - 1)) * amplitude, x, y);
		}

		prev = temp;
		temp = temp->next;
		index++;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'q')
	{
		circlesList.insertAtHead(10 + std::rand() % 91);
	}

	if (key == 'w')
	{
		circlesList.insertAtTail(10 + std::rand() % 91);
	}

	if (key == 'a')
	{
		circlesList.deleteHead();
	}

	if (key == 's')
	{
		circlesList.deleteTail();
	}

	if (key == 'e')
	{
		circlesList.sortAscending();
	}

	if (key == 'z')
	{
		amplitude += 5.0f;
	}
	
	if (key == 'x')
	{
		amplitude = std::max(5.0f, amplitude - 5.0f);
	}
	
	if (key == OF_KEY_LEFT)
	{
		cameraOffset += cameraSpeed;
	}
	
	if (key == OF_KEY_RIGHT)
	{
		cameraOffset -= cameraSpeed;
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
