#include <iostream>

class Node
{
public:
	int info;
	Node *next;
}* Start;

Node* ceateNode(int value)
{
	Node *temp, *s;
	temp = new Node;
	temp->info = value;
	temp->next = nullptr;

	return temp;
}

void insert_begin()
{
	int value;
	std::cout << "Enter value to be inserted: ";
	std::cin >> value;
	Node *temp, *p;
	temp = ceateNode(value);
	if (Start == nullptr)
	{
		Start = temp;
		Start->next =  nullptr;
	}
	else
	{
		p = Start;
		Start = temp;
		Start->next = p;
	}
	std::cout << "Element inserted at beginning" << std::endl;
}

void insert_pos()
{
	int value, pos, counter = 0;
	std::cout << "Enter value to be inserted: ";
	std::cin >> value;
	Node *temp, *s, *ptr;
	temp = ceateNode(value);
	std::cout << "Enter position at which to insert node: ";
	std::cin >> pos;
	int i;
	s = Start;

	while (s != nullptr)
	{
		s = s->next;
		counter++;
	}
	if (pos == 1)
	{
		if (Start == nullptr)
		{
			Start = temp;
			Start->next = nullptr;
		}
		else
		{
			ptr = Start;
			Start = temp;
			Start->next = ptr;
		}
	}
	else if (pos > 1 && pos <= counter)
	{
		s = Start;
		for (i = 1; i < pos; i++) {
			ptr = s;
			s = s->next;
		}
		ptr->next = temp;
		temp->next = s;
	} else {
		std::cout << "Position out of range" << std::endl;
	}
}

void delete_pos()
{
	int pos, i, counter = 0;
	if (Start == nullptr)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	std::cout << "Enter the position of the value to be deleted: ";
	std::cin >> pos;
	struct Node *s, *ptr;
	s = Start;
	if (pos == 1)
	{
		Start = s->next;
	}
	else
	{
		while (s != nullptr)
		{
			s = s->next;
			counter++;
		}
	}
}

void search()
{
	int key, pos = 0;
	if (Start == nullptr)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	std::cout<<"Enter key to search: ";
	std::cin>>key;
	Node *temp;
	temp = Start;
	bool f;
	while (temp != nullptr)
	{
		pos++;
		if (temp->info == key)
		{
			f = true;
			std::cout << "Key " << key << " is found at position "<<pos<<std::endl;
		}
		temp = temp->next;
	}
	if (!f){
		std::cout<< "Key " << key << " not found in the list"<< std::endl;
	}
}

int main() {
	std::cout << "List test - Insert item" << std::endl;
	insert_begin();
	insert_pos();
	delete_pos();
	search();
	return 0;
}
