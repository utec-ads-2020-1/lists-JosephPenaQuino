#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <class T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator();
        BidirectionalIterator(Node<T>*);

        BidirectionalIterator<T> operator=(BidirectionalIterator<T>);

        bool operator!=(BidirectionalIterator<T>);

        BidirectionalIterator<T> operator++();

        BidirectionalIterator<T> operator--();

        T operator*();
};
template <class T> 
BidirectionalIterator<T>::BidirectionalIterator()
{

}

template <class T> 
BidirectionalIterator<T>::BidirectionalIterator(Node<T>*)
{

}

template <class T> 
BidirectionalIterator<T> BidirectionalIterator<T>::operator=(BidirectionalIterator<T>)
{

}

template <class T> 
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T>)
{

}

template <class T> 
BidirectionalIterator<T> BidirectionalIterator<T>::operator++()
{

}

template <class T> 
BidirectionalIterator<T> BidirectionalIterator<T>::operator--()
{

}

template <class T> 
T BidirectionalIterator<T>::operator*()
{
    
}

#endif