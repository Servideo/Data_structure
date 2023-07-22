#pragma once
#ifndef STACK_HPP
#define STACK_HPP

#include <sstream>
#include <string>

#include "node.hpp"


template <class T>
class Stack
{
private:
    Node<T> *top, *tail;
    int size;

    std::string converToString(T data)
    {
        std::stringstream text;
        text << data;
        return text.str();
    }

public:
    Stack()
    {
        this->top = this->tail = nullptr;
        this->size = 0;
    }

    ~Stack() {}

    int getSize()
    {
        return this->size;
    }

    Node<T> *peek()
    {
        if (this->isEmpty()) throw std::invalid_argument("Stack is empty");
        return this->top;
    }

    Node<T> *getTail()
    {
        if (this->isEmpty()) throw std::invalid_argument("Stack is empty");
        return this->tail;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        this->size++;
        if (this->isEmpty())
        {
            this->top = this->tail = newNode;
            return;
        }
        newNode->next = this->top;
        this->top = newNode;
    }

    void pop()
    {
        if (this->isEmpty())
            throw std::invalid_argument("Stack is empty");
        this->size--;
        Node<T> *temp = this->top;
        this->top = temp->next;
        if (this->top == nullptr)
            this->tail == nullptr;
        delete (temp);
    }

    bool isEmpty()
    {
        return (this->top == nullptr) ? true : false;
    }

    void clear()
    {
        Node<T> *temp = this->top;
        this->top = this->tail = nullptr;
        this->size = 0;
        delete (temp);
    }

    std::string toString()
    {
        if (this->isEmpty())
            return "[]";
        Node<T> *temp = this->top;
        std::string msg = this->converToString(temp->data);
        temp = temp->next;
        while (temp)
        {
            msg += " " + this->converToString(temp->data);
            temp = temp->next;
        }
        return msg;
    }
};

#endif
