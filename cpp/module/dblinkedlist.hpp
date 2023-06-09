#pragma once
#ifndef DBLINKEDLIST_H
#define DBLINKEDLIST_H

#include <string>
#include <sstream>

#include "node.hpp"

template <class T>
class DoublyLinkedList
{
private:
    Node<T> *head, *tail;
    int size;

    std::string convertoString(T data)
    {
        std::stringstream text;
        text << data;
        return text.str();
    }

public:
    DoublyLinkedList()
    {
        this->head = this->tail = nullptr;
        this->size = 0;
    }
    
    ~DoublyLinkedList(){}

    Node<T>* getHead()
    {
        return this->head;
    }

    Node<T>* getTail()
    {
        return this->tail;
    }

    int getSize()
    {
        return this->size;
    }
    
    Node<T>* get(int index)
    {
        if (index >= this->size || index < 0)
           throw std::invalid_argument("List index out range");
        else if (index == 0)
            return this->head;
        else if (index == this->size - 1)
            return this->tail;
        Node<T> *temp = this->head->next;
        for (int i = 1; i < index; i++)
            temp = temp->next;
        return temp;
    }

    void add(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        this->size++;
        if(this->isEmpty())
        {
            this->head = this->tail = newNode;
            return;
        }
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }
    
    void pop(int index)
    {
        if(index >= this->size || index < 0)
            throw std::invalid_argument("List index out range");
        Node<T>* temp = this->head;
        int lenght = this->getSize();
        this->size--;
        if(index == 0)
        {
            this->head = temp->next;
            temp->prev = this->head->prev;
            delete(temp);
            return;
        }
        else if(index == lenght - 1)
        {
            temp = this->tail;
            this->tail = temp->prev;
            this->tail->next = temp->next;
            delete(temp);
            return;
        }
        temp = temp->next;
        Node<T>* prev = temp->prev;
        for(int i = 1; i < index; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next->prev = prev;
        delete(temp);
    }

    bool isEmpty()
    {
        return (this->head == nullptr) ? true : false;
    }

    void clear()
    {
        this->head = this->tail = nullptr;
        this->size = 0;
    }

    std::string toString()
    {
        if (this->isEmpty())
            return "[]";
        Node<T> *temp;
        std::string msg = "";
        temp = this->head;
        msg += this->convertoString(temp->data);
        temp = temp->next;
        while (temp)
        {
            msg += " " + this->convertoString(temp->data);
            temp = temp->next;
        }
        return msg;
    }

    void reverse()
    {
        if (this->isEmpty() || this->size < 2)
            return;   
        this->tail = this->head;
        Node<T> *prev = this->head->prev;
        Node<T> *current = this->head;
        Node<T> *next;
        while(current)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        this->head = prev;
    }
};

#endif