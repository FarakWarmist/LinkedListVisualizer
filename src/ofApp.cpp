#include "ofApp.h"
#include <cstdlib>
#include <ctime>

//--------------------------------------------------------------
void ofApp::setup(){
	circlesList.insertAtHead(10 + std::rand() % 91);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	Node* temp = circlesList.head;
	Node* prev = nullptr;
	index = 0;

	while (temp != nullptr) {
		ofSetColor(255);
		ofDrawCircle(100 + index * 200, 200, temp->data);
		ofSetColor(0);
		ofDrawBitmapString(ofToString(temp->data), (100 + index * 200) - 5, 200 + 5);

		if (prev != nullptr)
		{
			ofSetColor(255);
			ofDrawLine(100 + (index - 1) * 200, 200, 100 + index * 200, 200);
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

	if (key == 'e')
	{
		circlesList.sortAscending();
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
