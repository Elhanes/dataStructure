#pragma once
//#include <iostream>

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
	singleLinkedList()
	{
		head = tail = new singleLinkedList_Node<T>(NULL, nullptr);
		num_node = 0;
	}
	
	void push_front(T value)
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

	void push_back(T value)
	{
		singleLinkedList_Node<T>* node = new singleLinkedList_Node<T>(value, nullptr);

		if (head->next != nullptr) tail->next = node;

		tail = node;
		num_node++;
	}

	T pop_front()
	{
		T val;

		if (head->next != nullptr) // check list is not empty
		{
			singleLinkedList_Node<T>* tmp = head->next;
			head->next = head->next->next;
			val = tmp->value;
			delete tmp;
			num_node--;
		}

		// need to add error case - be called when the list is empty

		return val;
	}

	T pop_back()
	{
		T val;

		if (head->next != nullptr) // check list is not empty
		{
			singleLinkedList_Node<T>* tmp = tail;
			singleLinkedList_Node<T>* scan = head;

			while (scan->next != tail) scan = scan->next;

			scan->next = nullptr;
			tail = scan;
			val = tmp->value;
			delete tmp;
			num_node--;
		}

		// need to add error case - be called when the list is empty

		return val;
	}

	T get_head()
	{
		if (head->next != nullptr) return head->next->value;
		else return 0;
	}

	T get_tail()
	{
		if (head->next != nullptr) return tail->value;
		else return 0;
	}

	int size() { return num_node; }
	
	bool empty()
	{
		if (num_node == 0) return 1;
		else return 0;
	}

	~singleLinkedList()
	{
		while (head->next != nullptr) pop_front();
		delete head;
	}
};