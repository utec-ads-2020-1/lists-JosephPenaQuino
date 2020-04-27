#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T>
{
    private:
        void divide_fordward_list(Node<T> *n, Node<T> **a, Node<T> **b);
        void merge_sort(Node<T> **n);
        Node<T> * merge_s(Node<T> *a, Node<T> *b);
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
        void insert(int, T);
        void insert_after(ForwardIterator<T>, T);

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
void ForwardList<T>::merge_sort(Node<T> **n)
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
void ForwardList<T>::divide_fordward_list(Node<T> *n, Node<T> **a, Node<T> **b)
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
Node<T> * ForwardList<T>::merge_s(Node<T> *a, Node<T> *b)
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
void ForwardList<T>::sort()
{
    if (this->empty())
        return;
    this->merge_sort(&(this->head));
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
void ForwardList<T>::insert(int index, T data)
{
    if (this->empty())
        return;
    if (index > this->nodes)
        return;
    else if (index==0)
        this->push_front(data);
    else if (index==this->nodes)
        this->push_back(data);
    else
    {
        Node<T> ** temp = &(this->head->next);
        for (int i=0; i < index; ++i)
            (*temp) = (*temp)->next;
        
        Node<T> * new_node = new Node<T>(data);
        new_node->next=(*temp)->next;
        (*temp)->next = new_node;
    }

}

template <class T>
void ForwardList<T>::insert_after(ForwardIterator<T> it, T data)
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
        it.current->next = new_node;
    }
}

template <class T>
void ForwardList<T>::merge(ForwardList<T>& other)
{
    ForwardIterator<T> it = this->begin();

    if (it == nullptr)
    {
        while(!other.empty())
        {
            this->push_back(other.front());
            other.pop_front();
        }
    }
    bool pass=false;
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
template <class T>
ForwardIterator<T> ForwardList<T>::begin()
{
    return ForwardIterator<T>(this->head);
}
template <class T>
ForwardIterator<T> ForwardList<T>::end()
{
    return ForwardIterator<T>(nullptr);
}

#endif