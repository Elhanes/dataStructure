#include <iostream>
#include "singleLinkedList.h"

int main()
{
	singleLinkedList<char> sll_char;
	singleLinkedList<int> sll_int;
	singleLinkedList<float> sll_float;

	//insert char to list
	sll_char.push_front('a');
	sll_char.push_front('b');
	sll_char.push_front('c');
	sll_char.push_back('d');
	sll_char.push_back('e');

	//insert int to list
	for (int i = 0; i < 5; i++) sll_int.push_front(i);
	for (int i = 5; i < 10; i++) sll_int.push_back(i);

	//insert float to list
	for (int i = 1; i < 6; i++) sll_float.push_front(i + 0.1);

	//test size
	std::cout << "char list size : " << sll_char.size() << ", int list size : " << sll_int.size() << ", float list size : " << sll_float.size() << "\n";
	std::cout << "----------------------------\n";

	//test pop_front and get_head
	while (!sll_char.empty())
	{
		std::cout << sll_char.get_head() << " ";
		sll_char.pop_front();
	}

	std::cout << "\n----------------------------\n";

	//test pop_back and get_tail
	while (!sll_int.empty())
	{
		std::cout << sll_int.get_head() << " ";
		std::cout << sll_int.get_tail() << " ";
		sll_int.pop_front();
		sll_int.pop_back();
	}

	std::cout << "\n";

	//test empty
	if (sll_int.empty()) std::cout << "int list is empty\n";
	else std::cout << "int list is not empty\n";

	std::cout << "----------------------------\n";

	while (!sll_float.empty())
	{
		std::cout << sll_float.get_head() << " ";
		sll_float.pop_front();
	}

	std::cout << "\n----------------------------";

	return 0;
}