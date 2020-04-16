#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <class T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator();
        ForwardIterator(Node<T>*);

        ForwardIterator<T> operator=(ForwardIterator<T>);

        bool operator!=(ForwardIterator<T>);

        ForwardIterator<T> operator++();

        T operator*();
};
template <class T> 
ForwardIterator<T>::ForwardIterator()
{

}

template <class T> 
ForwardIterator<T>::ForwardIterator(Node<T>*)
{

}

template <class T> 
ForwardIterator<T> ForwardIterator<T>::operator=(ForwardIterator<T>)
{

}

template <class T> 
bool ForwardIterator<T>::operator!=(ForwardIterator<T>)
{

}

template <class T> 
ForwardIterator<T> ForwardIterator<T>::operator++()
{

}

template <class T> 
T ForwardIterator<T>::operator*()
{

}

#endif