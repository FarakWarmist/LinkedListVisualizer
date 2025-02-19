#pragma once

#include "ofMain.h"

class Node {

public:
	int data;
	Node* next;
};

class LinkedList {

public:
	Node* head;

	LinkedList()
	{
		head = nullptr;
	}

	void insertAtHead(int value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}

	void insertAtTail(int value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	void deleteHead()
	{
		if (head == nullptr)
		{
			return;
		}

		Node* temp = head;
		head = head->next;
		delete temp;
	}

	void deleteTail()
	{
		if (head == nullptr)
		{
			return;
		}

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node* temp = head;

		while (temp->next != nullptr && temp->next->next != nullptr)
		{
			temp = temp->next;
		}

		delete temp->next;
		temp->next = nullptr;
	}

	void sortAscending()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}

		Node* temp = head;
		while (temp)
		{
			Node* minNode = temp;
			Node* nextNode = temp->next;

			while (nextNode)
			{
				if (nextNode->data < minNode->data)
				{
					minNode = nextNode;
				}
				nextNode = nextNode->next;
			}

			if (minNode != temp)
			{
				std::swap(temp->data, minNode->data);
			}
			
			temp = temp->next;
		}

	}

};

class ofApp : public ofBaseApp{

	public:
		float x = 100.0f;
		int index = 0;
		LinkedList circlesList;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};


