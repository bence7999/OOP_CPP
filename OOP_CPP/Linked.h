#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

class Node
{
public:
	int key;
	Node * next;
	Node(int n); //for key
};

class LinkList
{
protected:
	Node * root;
	Node *tail;
public:
	LinkList();
	void addNode(int M);
	void show();
};

LinkList::LinkList()
{
	root = NULL;
	tail = NULL;
};

void LinkList::show()
{
	Node * temp;
	if (root == NULL)
		cout << "Linked List is empty" << endl;
	else
	{
		temp = root;
		while (temp != NULL)
		{
			cout << setw(5) << temp->key;
			temp = temp->next;//temp points where temp->next points
		}
	}
};

Node::Node(int n) //for key
{
	key = n;
	next = NULL;
}

void LinkList::addNode(int M)
{
	Node *temp = new Node(M);
	if (tail == NULL)
	{
		tail = temp;
		root = tail;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}