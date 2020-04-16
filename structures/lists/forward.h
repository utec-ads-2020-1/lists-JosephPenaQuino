#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        void merge_sort(Node<T> *n, int l, int r);
        void merge_s(Node<T> *n, int l, int m, int r);
    public:
        ForwardList();

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

        ForwardIterator<T> begin();
	    ForwardIterator<T> end();

        string name() {
            return "Forward List";
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
        void merge(ForwardList<T>&);
};

template <class T>
ForwardList<T>::ForwardList() : List<T>() {}

template <class T>
T ForwardList<T>::front()
{
    if (this->empty())
        return T();
    
    return this->head->data;
}

template <class T>
T ForwardList<T>::back()
{
    if (this->empty())
        return T();
    
    return this->tail->data;
}

template <class T>
void ForwardList<T>::push_front(T data)
{
    Node<T> * temp = new Node<T>(data);
    if (this->empty())
    {
        this->tail = temp;
        this->head = temp;
    }
    else
    {
        temp->next = this->head;
        this->head = temp;
    }
    this->nodes++;
}

template <class T>
void ForwardList<T>::push_back(T data)
{
    Node<T> * temp = new Node<T>(data);
    if (this->empty())
    {
        this->tail = temp;
        this->head = temp;
    }
    else
    {
        this->tail->next = temp;
        this->tail = temp;
    }
    this->nodes++;
}

template <class T>
void ForwardList<T>::pop_front()
{
    if (this->empty())
        return;

    Node<T> * temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->nodes--;
}

template <class T>
void ForwardList<T>::pop_back()
{
    if (this->empty())
        return;
    Node<T> * current_node = this->head;

    for (int i=0; i < this->nodes-2; ++i)
        current_node = current_node->next;
    current_node->next = nullptr;
    delete this->tail;
    this->tail = current_node;
    this->nodes--;
}

template <class T>
T ForwardList<T>::operator[](int index)
{
    if (this->empty())
        return T();
    
    Node<T> * temp = this->head;
    for (int i = 0; i< index; ++i)
        temp = temp->next;
    
    return temp->data;
}

template <class T>
bool ForwardList<T>::empty()
{
    return this->nodes == 0;
}

template <class T>
int ForwardList<T>::size()
{
    return this->nodes;
}

template <class T>
void ForwardList<T>::clear()
{

}

template <typename T>
void ForwardList<T>::merge_sort(Node<T> *n, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        merge_sort(n, l, m);
        merge_sort(n, m+1, r);

        merge_s(n, l, m, r);
    }
}

template <typename T>
void ForwardList<T>::merge_s(Node<T> *n, int l, int m, int r)
{
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];
    for (i=0; i < n1; ++i)
        L[i] = 
}
template <class T>
void ForwardList<T>::sort()
{
    if (this->empty())
        return;
    this->merge_sort(this->head, 0, nodes);
}

template <class T>
void ForwardList<T>::reverse()
{
    int my_size = this->nodes;
    Node<T> *temp = this->head;

    for (int i=0; i < my_size; ++i)
    {
        this->push_front(temp->data);
        temp = temp->next;
    }   
    for (int i=0; i < my_size; ++i)
        this->pop_back();
}
template <class T>
void ForwardList<T>::merge(ForwardList<T>&)
{

}
template <class T>
ForwardIterator<T> ForwardList<T>::begin()
{

}
template <class T>
ForwardIterator<T> ForwardList<T>::end()
{

}


#endif