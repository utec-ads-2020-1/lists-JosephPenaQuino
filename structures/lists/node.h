#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    void killSelf();
    Node(T element) : data{element}, next{nullptr}, prev{nullptr} {}
    Node(T element, Node<T>* next) : data{element}, next{next}, prev{nullptr} {}
};

#endif