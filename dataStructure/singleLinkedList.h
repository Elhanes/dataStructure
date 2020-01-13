#pragma once
#include <iostream>

class singleLinkedList_Node
{

	friend class singleLinkedList;

private:
	int value;
	singleLinkedList_Node* next;
	singleLinkedList_Node(int value, singleLinkedList_Node* next) : value(value), next(next) { }
};

class singleLinkedList
{
private:
	singleLinkedList_Node* head;
	singleLinkedList_Node* tail;
	int num_node;

public:
	singleLinkedList();
	void push_front(int);
	void push_back(int);
	int pop_front();
	int pop_back();
	int get_head();
	int get_tail();
	int size();
	bool empty();

	~singleLinkedList();
};