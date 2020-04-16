#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <class T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front();
        T back();
        void push_front(T);
        void push_back(T);
        void pop_front();
        void pop_back();
        T operator[](int);
        bool empty();
        int size();
        void clear();
        void sort();
        void reverse();

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() {
            return "Circular Linked List";
        }

        /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
        void merge(CircularLinkedList<T>&);
};
template <class T>
T CircularLinkedList<T>::front()
{

}

template <typename T>
T CircularLinkedList<T>::back()
{

}

template <typename T>
void CircularLinkedList<T>::push_front(T)
{

}

template <typename T>
void CircularLinkedList<T>::push_back(T)
{

}

template <typename T>
void CircularLinkedList<T>::pop_front()
{

}

template <typename T>
void CircularLinkedList<T>::pop_back()
{

}

template <typename T>
T CircularLinkedList<T>::operator[](int)
{

}

template <typename T>
bool CircularLinkedList<T>::empty()
{

}

template <typename T>
int CircularLinkedList<T>::size()
{

}

template <typename T>
void CircularLinkedList<T>::clear()
{

}

template <typename T>
void CircularLinkedList<T>::sort()
{

}

template <typename T>
void CircularLinkedList<T>::reverse()
{

}

template <typename T>
BidirectionalIterator<T> CircularLinkedList<T>::begin()
{

}

template <typename T>
BidirectionalIterator<T> CircularLinkedList<T>::end()
{

}

template <typename T>
void CircularLinkedList<T>::merge(CircularLinkedList<T>&)
{
    
}
#endif