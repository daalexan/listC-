#pragma once
#ifndef LISTS_H
#define LISTS_H

template<class T>
class List
{
public:
	List();
	~List() {}
	void Add(T data);
	void AddFront(T data);
	void AddAt(int ind, T data);
	void Clear();
	void RemoveFront();
	void RemoveAt(int n);
	void RemoveEnd();
	int Count();
	T operator[](int n);
private:
	template<class LstT>
	class Node
	{
	public:
		LstT data;
		Node *pNext;
		Node(LstT data = LstT(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
		~Node() {}
	};
	int Size;
	Node<T> *head;
};

template<class T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<class T>
void List<T>::Add(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
			current = current->pNext;
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<class T>
void List<T>::AddFront(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<class T>
void List<T>::AddAt(int ind, T data)
{
	int i = 1;
	Node<T> *current = this->head;
	ind--;
	while (i < ind)
	{
		current = current->pNext;
		i++;
	}
	Node<T> *node = new Node<T>(data, current->pNext);
	current->pNext = node;
	Size++;
}

template<class T>
void List<T>::RemoveAt(int n)
{
	if (n == 0)
	{
		RemoveFront();
	}
	else
	{
		int i = 1;
		Node<T> *current = this->head;
		n--;
		while (i < n)
		{
			current = current->pNext;
			i++;
		}
		Node<T> *node = current->pNext;
		current->pNext = current->pNext->pNext;
		delete node;
	}
	Size--;
}

template<class T>
void List<T>::RemoveEnd()
{
	Node<T> *current = this->head;
	while (current->pNext != nullptr)
		current = current->pNext;
	delete current;
	Size--;
}

template<class T>
int List<T>::Count()
{
	return (Size);
}

template<class T>
T List<T>::operator[](int n)
{
	int i = 0;
	Node<T> *current = this->head;
	while (i < n && current->pNext != nullptr)
	{
		current = current->pNext;
		i++;
	}
	return (current->data);
}

template<class T>
void List<T>::RemoveFront()
{
	Node<T> *temp = this->head;
	this->head = this->head->pNext;
	delete temp;
	Size--;
}

template<class T>
void List<T>::Clear()
{
	while (Size != 0)
	{
		RemoveFront();
	}
}

#endif