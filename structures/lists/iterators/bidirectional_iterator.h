#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"
#include "../linked.h"
// #include "../circular.h"

// TODO: Implement all methods
template <class T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

        template<class B> friend class LinkedList;
        // template<class C> friend class CircularLinkedList;
    public:
        BidirectionalIterator();
        BidirectionalIterator(Node<T>*);

        BidirectionalIterator<T> operator=(BidirectionalIterator<T>);

        bool operator!=(BidirectionalIterator<T>);
        bool operator==(BidirectionalIterator<T>);

        BidirectionalIterator<T> operator++();

        BidirectionalIterator<T> operator--();

        T operator*();
};
template <class T> 
BidirectionalIterator<T>::BidirectionalIterator() : current{nullptr} {}

template <class T> 
BidirectionalIterator<T>::BidirectionalIterator(Node<T>* node) : current{node} {}

template <class T> 
BidirectionalIterator<T> BidirectionalIterator<T>::operator=(BidirectionalIterator<T> it)
{
    current = it.current;
    return *this;
}

template <class T> 
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T> it)
{
    return this->current != it.current;
}

template <class T> 
bool BidirectionalIterator<T>::operator==(BidirectionalIterator<T> it)
{
    return current == it.current;
}

template <class T> 
BidirectionalIterator<T> BidirectionalIterator<T>::operator++()
{
    current = current->next;
}

template <class T> 
BidirectionalIterator<T> BidirectionalIterator<T>::operator--()
{
    current = current->prev;
}

template <class T> 
T BidirectionalIterator<T>::operator*()
{
    return current->data;
}

#endif