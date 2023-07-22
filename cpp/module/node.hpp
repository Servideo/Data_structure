#pragma once
#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node
{
public:
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    T data;

    Node(T data) : data(data)
    {
    }

    ~Node() {}
};

#endif
