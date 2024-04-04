#pragma once
#include <iostream>
using namespace std;

//class Queue with all the functions that allows the user to add, remove, change position, check the size, and check if it's empty

template<typename Item_Type>
class Queue {
private:
	struct Node {
		Item_Type data;
		Node* next;
		Node(const Item_Type& data): data(data), next(nullptr){}
	};
	
	Node* headPtr;
	Node* tailPtr;
	size_t queueSize;

public:
	Queue(): headPtr(nullptr), tailPtr(nullptr), queueSize(0){}

	~Queue() {
		while (!empty()) {
			pop();
		}
	}

	void push(const Item_Type& value) {
		Node* newNode = new Node(value);
		if (empty()) {
			headPtr = newNode;
		}
		else {
			tailPtr->next = newNode;
		}
		tailPtr = newNode;
		++queueSize;
	}

	void pop() {
		if (empty()) {
			cerr << "Queue is empty. Cannot pop.\n";
			return;
		}
		Node* temp = headPtr;
		headPtr = headPtr->next;
		delete temp;
		--queueSize;
		if (empty()) {
			tailPtr = nullptr;
		}
	}

	Item_Type& front() const {
		if (empty()) {
			throw std::out_of_range("Queue is empty. No front element.");
		}
		return headPtr->data;
	}

	size_t size() const {
		return queueSize;
	}

	bool empty() const {
		if (queueSize == 0)
			return true;
		else
			return false;
	}

	void move_to_rear() {
		if (empty() || size() == 1) {
			cerr << "Queue has insufficient elements for moving.\n";
			return;
		}
		Item_Type frontValue = front();
		pop();
		push(frontValue);
	}
};
