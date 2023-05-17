#include "node.h"
#include <string>
#include <sstream>

template <class T>
class LinkedList
{
private:
    Node<T> *head, *last;
    int size;
    std::string convertToString(T element)
    {
        std::stringstream s;
        s << element;
        return s.str();
    }

public:
    LinkedList<T>()
    {
        this->head = this->last = NULL;
        this->size = 0;
    }
    Node<T> *get(int index)
    {
        if (index >= this->size || index < 0)
            throw std::invalid_argument("List index out range");
        Node<T> *current = this->head;
        if (index == 0)
            return current;
        else if (index == this->size - 1)
            return this->last;
        current = current->next;
        for (int i = 1; i < index; i++)
            current = current->next;
        return current;
    }

    int getSize()
    {
        return this->size;
    }
    // metodos
    bool isEmpty()
    {
        if (this->head == NULL)
            return true;
        return false;
    }

    void add(T data)
    {
        this->size++;
        Node<T>* newNode = new Node(data);
        if (this->isEmpty())
        {
            this->head = this->last = newNode;
            return;
        }
        this->last->next = newNode;
        this->last = newNode;
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
            prev->next = this->last->next;
            this->last = prev;
            delete(current);
            return;
        }
        prev->next = current->next;
        delete(current);
    }

    void clear()
    {
        this->head = this->last = NULL;
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
        Node<T> *prev = NULL;
        Node<T> *current = this->head;
        Node<T> *next;
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