#include "node.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class LinkedList
{
private:
    // Atributos
    Node<T> *head;
    Node<T> *last;
    int size;
    string convertToString(T element){
        stringstream s;
        s << element;
        return s.str();
    }

public:
    // constructor
    LinkedList<T>()
    {
        this->head = NULL;
        this->last = NULL;
        this->size = 0;
    }
    // getter
    T get(int index)
    {
        if (index == 0) return this->head->data;
        else if (index == size - 1) return this->last->data;
        Node<T> *current = this->head->next;
        for (int i = 1; i < index; i++)
            current = current->next;
        return current->data;
    }
    int getSize()
    {
        return this->size;
    }
    // metodos
    bool isEmpty(){
        if(this->head == NULL) return true;
        return false;
    }
    void add(T data)
    {
        size++;
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        if (this->isEmpty())
        {
            this->head = newNode;
            this->head->next = last;
            return;
        }
        else if (last == NULL)
        {
            this->last = newNode;
            head->next = this->last;
            last->next = NULL;
            return;
        }
        this->last->next = newNode;
        this->last = newNode;
        this->last->next = NULL;
    }
    string toString()
    {
        if (this->isEmpty()) return "Lista vacia";
        string msg;
        Node<T> *temp = this->head;
        msg = this->convertToString(temp->data);
        temp = temp->next;
        while (temp)
        {
            msg += " " + convertToString(temp->data);
            temp = temp->next;
        }
        return msg;
    }
    void reverse()
    {
        Node<T> *prev = NULL;
        Node<T> *next;
        Node<T> *current = this->head;
        this->last = this->head;
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