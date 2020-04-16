#ifndef STACK_H
#define STACK_H

#include "lists/node.h"

using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <class T>
class stack {
	Node<T>* data;
	int capacity;
	int _size;

public:
	stack(int size = MAX);
	stack(const stack<T> &);
	~stack();   		

	void push(T);
	T pop();
	T top();

	int size();
	bool empty();

};

template <class T>
stack<T>::stack(int size) : _size{0}, capacity{size}, data{nullptr} {}

template <class T>
stack<T>::stack(const stack<T> & other) :  _size{0}, capacity{other.capacity}, data{nullptr}
{
	// TODO: Implement reverse function
	if (this != &other)
	{
		for (int j=0; j < other._size;++j)
		{
			Node<T>* temp = other.data;
			for (int i=0;i < other._size-j;++i)
			{
				if (i== other._size-j-1)
					this->push(temp->data);
				temp=temp->next;
			}
		}
	}
}

template <class T>
stack<T>::~stack()
{

}

template <class T>
T stack<T>::pop()
{
	if (this->empty())
		// TODO: Implement assert
		return T();
	
	Node<T> * temp_node = data->next;
	delete data;
	data = temp_node;
	this->_size--;
	if (this->empty())
		// TODO: Implement assert
		return T();
	return this->top();
}

template <class T>
T stack<T>::top()
{
	return data->data;
}

template <class T>
int stack<T>::size()
{
	return this->_size;
}

template <typename T>
bool stack<T>::empty()
{
	return this->_size == 0;
}

template <typename T>
void stack<T>::push(T element)
{
	if (this->empty())
	{
		this->data = new Node<T>(element);
	}
	else
	{
		Node<T> * new_node = new Node<T>(element, this->data);
		this->data = new_node;
	}
	this->_size++;
}

#endif