#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: 
//  - Destructor
//  - More eficcient []

template <class T>
class CircularLinkedList : public List<T> {
    private:
        void divide_fordward_list(Node<T> *n, Node<T> **a, Node<T> **b);
        void merge_sort(Node<T> **n);
        Node<T> * merge_s(Node<T> *a, Node<T> *b);
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
    if (this->empty())
        throw out_of_range("The circular linked list is empty!!");
    
    return this->head->data;
}

template <typename T>
T CircularLinkedList<T>::back()
{
    if (this->empty())
        throw out_of_range("The circular linked list is empty!!");
    
    return this->tail->data;
}

template <typename T>
void CircularLinkedList<T>::push_front(T data)
{
    Node<T> * temp = new Node<T>(data);
    if (this->empty())
        this->tail  = this->head = temp;
    else
    {
        temp->next = this->head;
        temp->prev = this->tail;
        this->head->prev = temp;
        this->head = temp;
    }
    this->nodes++;
}

template <typename T>
void CircularLinkedList<T>::push_back(T data)
{
    Node<T> * temp = new Node<T>(data);
    if (this->empty())
        this->tail = this->head  = temp;
    else
    {
        this->tail->next = temp;
        temp->prev = this->tail;
        temp->next = this->head;
        this->tail = temp;
    }
    this->nodes++;
}

template <typename T>
void CircularLinkedList<T>::pop_front()
{
    if (this->empty())
        throw out_of_range("The double linked list is empty!!!!");

    Node<T> * temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->head->prev = this->tail;
    this->nodes--;
}

template <typename T>
void CircularLinkedList<T>::pop_back()
{
    if (this->empty())
        throw out_of_range("The circular linked list is empty!!!!");

    Node<T> * temp = this->tail;
    this->tail = this->tail->prev;
    delete temp;
    this->tail->next = this->head;
    this->nodes--;
}

template <typename T>
T CircularLinkedList<T>::operator[](int index)
{
    if (this->empty())
        throw out_of_range("The double linked list is empty!");
    if (index < 0 || index >= this->nodes)
        throw out_of_range("The position is invalid!");
    
    Node<T> * temp = this->head;
    for (int i = 0; i< index; ++i)
        temp = temp->next;
    
    return temp->data;
}

template <typename T>
bool CircularLinkedList<T>::empty()
{
    return this->nodes == 0;
}

template <typename T>
int CircularLinkedList<T>::size()
{
    return this->nodes;
}

template <typename T>
void CircularLinkedList<T>::clear()
{

}

template <typename T>
void CircularLinkedList<T>::merge_sort(Node<T> **n)
{
    Node<T> *head = *n;
    if (head == nullptr || head->next == nullptr)
        return;

    Node<T> *a, *b;
    divide_fordward_list(*n, &a, &b);

    this->merge_sort(&a); 
    this->merge_sort(&b);

    *n = merge_s(a, b);
}

template<typename T>
void CircularLinkedList<T>::divide_fordward_list(Node<T> *n, Node<T> **a, Node<T> **b)
{
    Node<T> *fast, *slow; 
    slow = n; 
    fast = n->next; 

    while (fast != NULL)
    { 
        fast = fast->next; 
        if (fast != NULL)
        { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 

    *a = n; 
    *b = slow->next; 
    slow->next = NULL; 
}

template <typename T>
Node<T> * CircularLinkedList<T>::merge_s(Node<T> *a, Node<T> *b)
{
    Node<T> *res = nullptr;

    if (a == NULL)
        return (b); 
    else if (b == NULL) 
        return (a); 

    if (a->data <= b->data)
    { 
    res = a; 
    res->next = merge_s(a->next, b); 
    } 
    else
    { 
    res = b; 
    res->next = merge_s(a, b->next); 
    } 
    return res; 
}

template <typename T>
void CircularLinkedList<T>::sort()
{
    if (this->empty())
        return;
    this->merge_sort(&(this->head));
}

template <typename T>
void CircularLinkedList<T>::reverse()
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