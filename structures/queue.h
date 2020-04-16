#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class queue {
	T* data;
	T top;
	int _size;
	int capacity;

public:
	queue(int size = MAX);
	queue(const queue<T> &);
	~queue();   		

	void push(T);
	T pop();
	T front();
    T back();

	int size();
	bool empty();
};

template <class T>
queue<T>::queue(int size) : capacity{size}, data{nullptr}, _size{0}
{
	data = new T[capacity];
}

template <class T>
queue<T>::queue(const queue<T> & other): capacity{other.capacity}, data{nullptr}, _size{other._size}
{
	if (this != &other)
	{
		this->data = new T[capacity];
		for (int i=0; i<_size ;++i)
			this->data[i] = other.data[i];
	}
}

template <class T>
queue<T>::~queue()
{
	delete []data;
}

template <class T>
void queue<T>::push(T element)
{
	if (_size != capacity)
		data[_size] = element;
		this->_size++;
}

template <class T>
T queue<T>::pop()
{
	if (this->empty())
		return T();
	this->_size--;
	for (int i=0;i < _size; ++i)
		data[i] = data[i+1];
	if (this->empty())
		return T();
	return data[0];
}

template <class T>
T queue<T>::front()
{
	if (this->empty())
		return T();
	return data[0];
}

template <class T>
T queue<T>::back()
{
	if (this->empty())
		return T();
	return data[_size-1];
}

template <class T>
int queue<T>::size()
{
	return this->_size;
}

template <class T>
bool queue<T>::empty()
{
	return this->_size == 0;
}

#endif