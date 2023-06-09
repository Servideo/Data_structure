#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <sstream>

#include "node.hpp"


template <class T>
class LinkedList
{
private:
    Node<T> *head, *tail;
    int size;
    std::string convertToString(T element)
    {
        std::stringstream s;
        s << element;
        return s.str();
    }

public:
    LinkedList()
    {
        this->head = this->tail = nullptr;
        this->size = 0;
    }

    ~LinkedList(){}
    
    Node<T> *get(int index)
    {
        if (index >= this->size || index < 0)
            throw std::invalid_argument("List index out range");
        Node<T> *current = this->head;
        if (index == 0)
            return current;
        else if (index == this->size - 1)
            return this->tail;
        current = current->next;
        for (int i = 1; i < index; i++)
            current = current->next;
        return current;
    }

    Node<T> *getHead()
    {
        return this->head;
    }

    Node<T> *getTail()
    {
        return this->tail;
    }

    int getSize()
    {
        return this->size;
    }
    
    bool isEmpty()
    {
        return (this->head == nullptr) ? true : false;
    }

    void add(T data)
    {
        this->size++;
        Node<T>* newNode = new Node<T>(data);
        if (this->isEmpty())
        {
            this->head = this->tail = newNode;
            return;
        }
        this->tail->next = newNode;
        this->tail = newNode;
    }

    void pop(int index)
    {
        if (index >= this->size || index < 0)
            throw std::invalid_argument("List index out range");
        int length = this->getSize();
        this->size--;
        Node<T> *current = this->head;
        Node<T> *prev = this->head;
        if (index == 0)
        {
            this->head = current->next;
            delete(current);
            return;
        }
        current = current->next;
        for (int i = 1; i < index; i++)
        {
            prev = current;
            current = current->next;
        }
        if (index == length - 1)
        {
            prev->next = this->tail->next;
            this->tail = prev;
            delete(current);
            return;
        }
        prev->next = current->next;
        delete(current);
    }

    void clear()
    {
        this->head = this->tail = nullptr;
    }

    std::string toString()
    {
        if (this->isEmpty())
            return "[]";
        Node<T> *temp = this->head;
        std::string msg = this->convertToString(temp->data);
        temp = temp->next;
        while (temp)
        {
            msg += " " + this->convertToString(temp->data);
            temp = temp->next;
        }
        return msg;
    }
    
    void reverse()
    {
        if (this->isEmpty() || this->size < 2)
            return;
        Node<T> *prev = nullptr;
        Node<T> *current = this->head;
        Node<T> *next;
        this->tail = this->head;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
    }
};
#endif
