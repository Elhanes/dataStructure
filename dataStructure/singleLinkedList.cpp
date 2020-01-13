#include "singleLinkedList.h"

singleLinkedList::singleLinkedList()
{
	head = tail = new singleLinkedList_Node(NULL, NULL);
	num_node = 0;
}

void singleLinkedList::push_front(int value)
{
	singleLinkedList_Node* node = new singleLinkedList_Node(value, NULL);

	if (head->next == NULL)
	{
		head->next = node;
		tail = node;
	}
	else
	{
		singleLinkedList_Node* tmp = head->next;
		head->next = node;
		head->next->next = tmp;
	}

	num_node++;
}

void singleLinkedList::push_back(int value)
{
	singleLinkedList_Node* node = new singleLinkedList_Node(value, NULL);

	if (head->next != NULL) tail->next = node;

	tail = node;
	num_node++;
}

int singleLinkedList::pop_front()
{
	int val;

	if (head->next != NULL) // check list is not empty
	{
		singleLinkedList_Node* tmp = head->next;
		head->next = head->next->next;
		val = tmp->value;
		delete tmp;
		num_node--;
	}

	// need to add error case - be called when the list is empty

	return val;
}

int singleLinkedList::pop_back()
{
	int val;

	if (head->next != NULL) // check list is not empty
	{
		singleLinkedList_Node* tmp = tail;
		singleLinkedList_Node* scan = head;

		while (scan->next != tail) scan = scan->next;

		scan->next = NULL;
		tail = scan;
		val = tmp->value;
		delete tmp;
		num_node--;
	}

	// need to add error case - be called when the list is empty

	return val;
}

int singleLinkedList::get_head()
{
	if (head->next != NULL) return head->next->value;
	else return 0;
}

int singleLinkedList::get_tail()
{
	if (head->next != NULL) return tail->value;
	else return 0;
}

int singleLinkedList::size()
{
	return num_node;
}

bool singleLinkedList::empty()
{
	if (num_node == 0) return 1;
	else return 0;
}

singleLinkedList::~singleLinkedList()
{
	while (head->next != NULL) pop_front();
	delete head;
}