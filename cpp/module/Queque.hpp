#pragma once
#ifndef QUEQUE_H
#define QUEQUE_H

#include <sstream>
#include <string>

#include "node.hpp"


template <class T>
class Queque
{
private:
    Node<T> *front, *rear;
    int maxSize;
    int size;
    std::string convertToString(T data)
    {
        std::stringstream text;
        text << data;
        return text.str();
    }

public:
    Queque(int maxSize = 0)
    {
        this->front = this->rear = nullptr;
        this->size = 0;
        this->maxSize = maxSize;
    }

    ~Queque() {}

    Node<T> *getFront()
    {
        if (this->isEmpty())
            return nullptr;
        return this->front;
    }

    Node<T> *getBack()
    {
        if (this->isEmpty())
            return nullptr;
        return this->rear;
    }

    int getSize()
    {
        return this->size;
    }

    int getMaxSize()
    {
        return this->maxSize;
    }

    void setMaxSize(int maxSize = 0)
    {
        if (maxSize < this->maxSize)
            return;
        this->maxSize = maxSize;
    }

    bool isEmpty()
    {
        return (this->front == nullptr) ? true : false;
    }

    void enqueue(T data)
    {
        if (this->maxSize > 0 && this->size >= this->maxSize)
            return;
        Node<T> *temp = new Node<T>(data);
        this->size++;
        if (this->isEmpty())
        {
            this->front = this->rear = temp;
            return;
        }
        this->rear->next = temp;
        this->rear = temp;
    }

    void dequeue()
    {
        if (this->isEmpty())
            throw std::invalid_argument("Queue is empty");
        Node<T> *temp = this->front;
        this->size--;
        this->maxSize--;
        this->front = this->front->next;

        if (this->front == nullptr)
            this->rear == nullptr;
        delete temp;
    }

    void clear()
    {
        Node<T> *temp = this->front;
        this->front = this->rear = nullptr;
        this->size = this->maxSize = 0;
        delete temp;
    }

    std::string toString()
    {
        if (this->isEmpty())
            return "[]";
        Node<T> *temp = this->front;
        std::string msg = "[" + this->convertToString(temp->data);
        temp = temp->next;
        while (temp)
        {
            msg += " " + this->convertToString(temp->data);
            temp = temp->next;
        }
        msg += "]";
        return msg;
    }
};

#endif
