#ifndef STACK_H
#define STACK_H

#include "lists/node.h"

using namespace std;

#define MAX 1000 

template <class T>
class stack {
	T* data;
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
stack<T>::stack(int size) : _size{0}, capacity{size}, data{nullptr}
{
	data = new T[capacity];
}

template <class T>
stack<T>::stack(const stack<T> & other) :  _size{other._size}, capacity{other.capacity}, data{nullptr}
{
	if (this != &other)
	{
		this->data = new T[capacity];
		std::copy(other.data, other.data + other.capacity, data);
	}
}

template <class T>
stack<T>::~stack()
{
	delete [] data;
}

template <class T>
T stack<T>::pop()
{
	if (this->empty())
		throw out_of_range("The queue is empty!!!");
	_size--;
	return data[_size];
}

template <class T>
T stack<T>::top()
{
	return data[_size-1];
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
	if (_size >= capacity)
	{
		T * new_container = new T[capacity*2];
		std::copy(data, data + capacity, new_container);
		capacity = capacity*2;
		delete[] data;
		data = new_container;
	}
	data[_size] = element;
	this->_size++;
}

#endif