#include <iostream>
#include "singleLinkedList.h"

int main()
{
	singleLinkedList sll;


	sll.push_front(1);
	sll.push_front(2);
	sll.push_front(3);

	sll.push_back(4);
	sll.push_back(5);

	std::cout << "size of list is " << sll.size() << "\n";
	if (!sll.empty()) std::cout << "This single linked list is not empty\n";
	else std::cout << "This single linked list is empty\n";

	std::cout << "head of list is " << sll.get_head() << "\n";
	std::cout << "tail of list is " << sll.get_tail() << "\n";

	while (!sll.empty())
	{
		std::cout << sll.pop_front() << "\n";
	}

	std::cout << "size of list is " << sll.size() << "\n";
	if (!sll.empty()) std::cout << "This single linked list is not empty\n";
	else std::cout << "This single linked list is empty\n";

	std::cout << "head of list is " << sll.get_head() << "\n";
	std::cout << "tail of list is " << sll.get_tail() << "\n";

	return 0;
}