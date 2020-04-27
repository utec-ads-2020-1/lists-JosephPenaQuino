#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: 
//  - More eficcient []

template <class T>
class LinkedList : public List<T>
{
    private:
        void divide_linked_list(Node<T> *n, Node<T> **a, Node<T> **b);
        void merge_sort(Node<T> **n);
        Node<T> * merge_s(Node<T> *a, Node<T> *b);
    public:
        LinkedList() : List<T>() {}
        ~LinkedList();

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
            return "Linked List";
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
        void merge(LinkedList<T>&);
};
template <class T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}

template <class T>
T LinkedList<T>::front()
{
    if (this->empty())
        throw out_of_range("The double linked list is empty!!");
    
    return this->head->data;
}

template <class T>
T LinkedList<T>::back()
{
    if (this->empty())
        throw out_of_range("The double linked list is empty!!!");
    
    return this->tail->data;
}

template <class T>
void LinkedList<T>::push_front(T data)
{
    Node<T> * temp = new Node<T>(data);
    if (this->empty())
        this->tail  = this->head = temp;
    else
    {
        temp->next = this->head;
        this->head->prev = temp;
        this->head = temp;
    }
    this->nodes++;
}

template <class T>
void LinkedList<T>::push_back(T data)
{
    Node<T> * temp = new Node<T>(data);
    if (this->empty())
        this->tail = this->head  = temp;
    else
    {
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }
    this->nodes++;
}

template <class T>
void LinkedList<T>::pop_front()
{
    if (this->empty())
        return;
    else if (this->size() ==1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes--;
        return;
    }
    Node<T> * temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->head->prev = nullptr;
    this->nodes--;
}

template <class T>
void LinkedList<T>::pop_back()
{
    if (this->empty())
        return;
    else if (this->size() ==1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes--;
        return;
    }
    Node<T> * temp = this->tail;
    this->tail = this->tail->prev;
    delete temp;
    this->tail->next = nullptr;
    this->nodes--;
}

template <class T>
T LinkedList<T>::operator[](int index)
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
template <class T>
bool LinkedList<T>::empty()
{
    return this->nodes == 0;
}

template <class T>
int LinkedList<T>::size()
{
    return this->nodes;
}

template <class T>
void LinkedList<T>::clear()
{
    Node<T> *temp;
    while(this->head != nullptr)
    {
        temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->nodes--;
    }
    this->tail = nullptr;
}

template <typename T>
void LinkedList<T>::merge_sort(Node<T> **n)
{
    Node<T> *head = *n;
    if (head == nullptr || head->next == nullptr)
        return;

    Node<T> *a, *b;
    divide_linked_list(*n, &a, &b);

    this->merge_sort(&a); 
    this->merge_sort(&b);

    *n = merge_s(a, b);
}

template<typename T>
void LinkedList<T>::divide_linked_list(Node<T> *n, Node<T> **a, Node<T> **b)
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
Node<T> * LinkedList<T>::merge_s(Node<T> *a, Node<T> *b)
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

template <class T>
void LinkedList<T>::sort()
{
    if (this->empty())
        return;
    this->merge_sort(&(this->head));
}

template <class T>
void LinkedList<T>::reverse()
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
BidirectionalIterator<T> LinkedList<T>::begin()
{
    return BidirectionalIterator<T>(this->head);
}

template <class T>
BidirectionalIterator<T> LinkedList<T>::end()
{
    return BidirectionalIterator<T>(nullptr);
}

template <class T>
void LinkedList<T>::insert_after(BidirectionalIterator<T> it, T data)
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

template <class T>
void LinkedList<T>::merge(LinkedList<T>& other)
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