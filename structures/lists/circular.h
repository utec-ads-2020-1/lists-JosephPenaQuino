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
        Node<T>* sentinel;

        void divide_circular_list(Node<T> *n, Node<T> **a, Node<T> **b);
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
        void insert_after(BidirectionalIterator<T>, T);

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

// template <class T>
// CircularLinkedList<T>::CircularLinkedList() : List<T>() 
// {
    
// }

// template <class T>
// CircularLinkedList<T>::~CircularLinkedList() 
// {
//     this->clear();
//     delete this->sentinel;
// }


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
    {
        this->sentinel = new Node<T>();
        this->tail  = this->head = temp;

        this->tail->next = this->sentinel;
        this->head->prev = this->sentinel;

        this->sentinel->next = this->head;
        this->sentinel->prev = this->tail;
    }
    else
    {
        temp->next = this->head;
        temp->prev = this->sentinel;

        this->head->prev = temp;
        this->sentinel->next = temp;

        this->head = temp;
    }
    this->nodes++;
}

template <typename T>
void CircularLinkedList<T>::push_back(T data)
{
    Node<T> * temp = new Node<T>(data);
    if (this->empty())
    {
        this->sentinel = new Node<T>();
        this->tail = this->head  = temp;

        this->tail->next = this->sentinel;
        this->head->prev = this->sentinel;

        this->sentinel->next = this->head;
        this->sentinel->prev = this->tail;
    }
    else
    {
        temp->prev = this->tail;
        temp->next = this->sentinel;

        this->tail->next = temp;
        this->sentinel->prev = temp;

        this->tail = temp;
    }
    this->nodes++;
}

template <typename T>
void CircularLinkedList<T>::pop_front()
{
    if (this->empty())
        return;
    else if (this->size() == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->sentinel->next = nullptr;
        this->sentinel->prev = nullptr;
        this->nodes--;
        return;
    }
    Node<T> * temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->head->prev = this->sentinel;
    this->sentinel->next = this->head;
    this->nodes--;
}

template <typename T>
void CircularLinkedList<T>::pop_back()
{
    if (this->empty())
        return;
    else if(this->size() == 1)
    {
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
        this->sentinel->next = nullptr;
        this->sentinel->prev = nullptr;
        this->nodes--;
        return;
    }
    Node<T> * temp = this->tail;
    this->tail = this->tail->prev;
    delete temp;
    this->tail->next = this->sentinel;
    this->sentinel->prev = this->tail;
    this->nodes--;
}

template <typename T>
T CircularLinkedList<T>::operator[](int index)
{
    if (this->empty())
        throw out_of_range("The double linked list is empty!");
    if (index < 0 || index >= this->nodes)
        throw out_of_range("The index is invalid!");
    
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
    Node<T> *temp;
    int my_size = this->size();
    for (int i=0; i < my_size; ++i)
        this->pop_front();
}

template <typename T>
void CircularLinkedList<T>::merge_sort(Node<T> **n)
{
    if (*n == this->sentinel || (*n)->next == this->sentinel)
        return;

    Node<T> *a, *b;
    divide_circular_list(*n, &a, &b);

    this->merge_sort(&a); 
    this->merge_sort(&b);

    *n = merge_s(a, b);
}

template<typename T>
void CircularLinkedList<T>::divide_circular_list(Node<T> *n, Node<T> **a, Node<T> **b)
{
    Node<T> *fast, *slow; 
    slow = n; 
    fast = n->next; 

    while (fast != this->sentinel)
    { 
        fast = fast->next; 
        if (fast != this->sentinel)
        { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 

    *a = n; 
    *b = slow->next; 
    slow->next = this->sentinel;
}

template <typename T>
Node<T> * CircularLinkedList<T>::merge_s(Node<T> *a, Node<T> *b)
{
    Node<T> *res = this->sentinel;

    if (a == this->sentinel)
        return (b); 
    else if (b == this->sentinel) 
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
    return BidirectionalIterator<T>(this->head, this->sentinel);
}

template <typename T>
BidirectionalIterator<T> CircularLinkedList<T>::end()
{
    return BidirectionalIterator<T>(this->sentinel, this->sentinel);
}

template <class T>
void CircularLinkedList<T>::insert_after(BidirectionalIterator<T> it, T data)
{
    if (this->empty())
        return;
    if (it==this->begin())
        this->push_front(data);
    else if (it==this->end())
        this->push_front(data);
    else
    {
        Node<T> * new_node = new Node<T>(data);
        new_node->next = it.current->next;
        new_node->prev = it.current;
        it.current->next->prev = new_node;
        it.current->next = new_node;
    }
}

template <typename T>
void CircularLinkedList<T>::merge(CircularLinkedList<T>& other)
{
    BidirectionalIterator<T> it = this->begin();

    while (!other.empty())
    {
        if (it == nullptr)
            this->push_back(other.front());
        else if (*it < other.front())
            this->insert_after(it, other.front());
        else if (*it >= other.front())
            ++it;
        other.pop_front();
    }
}
#endif