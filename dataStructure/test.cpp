#include <iostream>
#include "singleLinkedList.h"

int main()
{
	singleLinkedList<char> sll;
	singleLinkedList<int> sll_int;

	sll.push_front('a');
	sll.push_front('b');
	sll.push_front('c');

	sll.push_back('d');
	sll.push_back('e');

	sll_int.push_front(1);
	sll_int.push_front(2);
	sll_int.push_front(3);

	sll_int.push_back(4);
	sll_int.push_back(5);

	std::cout << "size of list is " << sll.size() << "\n";
	if (!sll.empty()) std::cout << "This single linked list is not empty\n";
	else std::cout << "This single linked list is empty\n";

	std::cout << "head of list is " << sll.get_head() << "\n";
	std::cout << "tail of list is " << sll.get_tail() << "\n";

	std::cout << "-------------------------List contents----------------------------\n";

	while (!sll.empty())
	{
		std::cout << sll.pop_front() << " ";
	}
	std::cout << "\n";

	while (!sll_int.empty())
	{
		std::cout << sll_int.pop_front() << " ";
	}
	std::cout << "\n";
	std::cout << "------------------------------------------------------------------\n";

	std::cout << "size of list is " << sll.size() << "\n";
	if (!sll.empty()) std::cout << "This single linked list is not empty\n";
	else std::cout << "This single linked list is empty\n";

	std::cout << "head of list is " << sll.get_head() << "\n";
	std::cout << "tail of list is " << sll.get_tail() << "\n";

	return 0;
}