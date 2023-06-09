#pragma once
#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
    Node *prev, *next;
    T data;
    Node(T data)
    {
        this->prev = this->next = nullptr;
        this->data = data;
    }

    ~Node() {}
};

#endif
