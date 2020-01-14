#pragma once
#include <iostream>

template<class T> class singleLinkedList_Node;
template<class T> class singleLinkedList;

template <class T>
class singleLinkedList_Node
{
	friend class singleLinkedList<T>;

private:
	T value;
	singleLinkedList_Node* next;
	singleLinkedList_Node(T value, singleLinkedList_Node* next) : value(value), next(next) { }
};

template <class T>
class singleLinkedList
{
private:
	singleLinkedList_Node<T>* head;
	singleLinkedList_Node<T>* tail;
	int num_node;

public:
	singleLinkedList();
	~singleLinkedList();
	
	void push_front(T value);
	void push_back(T value);
	void pop_front();
	void pop_back();
	T get_head();
	T get_tail();
	int size();
	bool empty();
};

// inline function is automatically apply, on modern c++ version
template <class T>
singleLinkedList<T>::singleLinkedList()
{
	head = tail = new singleLinkedList_Node<T>(NULL, nullptr);
	num_node = 0;
}

template <class T>
void singleLinkedList<T>::push_front(T value)
{
	singleLinkedList_Node<T>* node = new singleLinkedList_Node<T>(value, nullptr);

	if (head->next == nullptr)
	{
		head->next = node;
		tail = node;
	}
	else
	{
		singleLinkedList_Node<T>* tmp = head->next;
		head->next = node;
		head->next->next = tmp;
	}

	num_node++;
}

template <class T>
void singleLinkedList<T>::push_back(T value)
{
	singleLinkedList_Node<T>* node = new singleLinkedList_Node<T>(value, nullptr);

	if (head->next == nullptr)
	{
		head->next = node;
		tail = node;
	}
	else tail->next = node;

	tail = node;
	num_node++;
}

template <class T>
void singleLinkedList<T>::pop_front()
{
	if (head->next != nullptr) // check list is not empty
	{
		singleLinkedList_Node<T>* tmp = head->next;
		head->next = head->next->next;
		delete tmp;
		num_node--;
	}
	else std::cout << "singleLinkedList::pop_front() : List is empty\n";
}

template <class T>
void singleLinkedList<T>::pop_back()
{
	if (head->next != nullptr) // check list is not empty
	{
		singleLinkedList_Node<T>* tmp = tail;
		singleLinkedList_Node<T>* scan = head;

		while (scan->next != tail) scan = scan->next;

		scan->next = nullptr;
		tail = scan;
		delete tmp;
		num_node--;
	}
	else std::cout << "singleLinkedList::pop_front() : List is empty\n";
}

template <class T>
T singleLinkedList<T>::get_head()
{
	if (head->next != nullptr) return head->next->value;
	else return 0;
}

template <class T>
T singleLinkedList<T>::get_tail()
{
	if (head->next != nullptr) return tail->value;
	else return 0;
}

template <class T>
int singleLinkedList<T>::size() 
{
	return num_node;
}

template <class T>
bool singleLinkedList<T>::empty()
{
	if (num_node == 0) return 1;
	else return 0;
}

template <class T>
singleLinkedList<T>::~singleLinkedList()
{
	while (head->next != nullptr) pop_front();
	delete head;
}

/* Implementation of the class

List node just include two datas, one is value, and other one is pointer of the next node.
This list just have one direction, but include head and tail node info. Only just these.
pop and get function is seperated. -> ..Same reason why STL stack and queue`s top(front) and pop function is seperated.
pop and get function is both side, head and tail.
But in pop_back function, for access to the node behind the tail, function will scan head to tail, because node only have one direction.
empty function return only status 0 and 1(bool type).
size function return int type constant.
Class template is applied.

next work : check the memory lick, and error handling on the pop function

written by elhanes
*/