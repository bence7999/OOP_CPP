#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

namespace LinkedT {
	
	template<class T>
	class Node
	{
	public:
		T key;
		Node * next;
		Node(T n); //for key
	};

	template <class T>
	class LinkList
	{
	protected:
		Node<T> *root;
		Node<T> *tail;
	public:
		LinkList();
		void addNode(T M);
		void show();
	};

	template <class T>
	LinkList<T>::LinkList()
	{
		root = NULL;
		tail = NULL;
	}

	template <class T>
	void LinkList<T>::show()
	{
		Node<T> * temp;
		if (root == NULL)
			cout << "Linked List is empty" << endl;
		else
		{
			temp = root;
			while (temp != NULL)
			{
				cout << setw(5) << temp->key;
				temp = temp->next;
				//temp points where temp->next points
			}
		}
	}

	template <class T>
	Node<T>::Node(T n) //for key
	{
		key = n;
		next = NULL;
	}

	template <class T>
	void LinkList<T>::addNode(T M)
	{
		Node<T> *temp = new Node<T>(M);
		if (tail == NULL)
		{
			tail = temp;
			root = tail;
		}
		else {
			tail->next = temp; //temp->next points where root points
			tail = temp;
		}
	}

}
