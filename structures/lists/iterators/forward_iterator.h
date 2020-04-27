#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"
#include "../forward.h"

// TODO: Add functionality to add -- from end()
template <class T> 
class ForwardIterator {
    private:
        Node<T> *current;

        template<class B> friend class ForwardList;
    public:
        ForwardIterator();
        ForwardIterator(Node<T>*);

        ForwardIterator<T> operator=(ForwardIterator<T>);

        bool operator!=(ForwardIterator<T>);
        bool operator==(ForwardIterator<T>);

        ForwardIterator<T> operator++();

        T operator*();
};
template <class T> 
ForwardIterator<T>::ForwardIterator() : current{nullptr} {}

template <class T> 
ForwardIterator<T>::ForwardIterator(Node<T>* node) : current{node} {}

template <class T> 
ForwardIterator<T> ForwardIterator<T>::operator=(ForwardIterator<T> it)
{
    current = it.current;
    return *this;
}

template <class T> 
bool ForwardIterator<T>::operator!=(ForwardIterator<T> it)
{
    return this->current != it.current;
}

template <class T> 
bool ForwardIterator<T>::operator==(ForwardIterator<T> it)
{
    return current == it.current;
}

template <class T> 
ForwardIterator<T> ForwardIterator<T>::operator++()
{
    current = current->next;
}

template <class T> 
T ForwardIterator<T>::operator*()
{
    return current->data;
}

#endif