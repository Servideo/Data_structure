#include "node.h"
#include <sstream>
#include <string>

template <class T>
class Stack
{
private:
    Node<T> *top;
    int size;
    std::string converToString(T data)
    {
        std::stringstream text;
        text << data;
        return text.str();
    }

public:
    Stack<T>()
    {
        this->top = NULL;
        this->size = 0;
    }

    int getSize()
    {
        return this->size;
    }

    Node<T> *peek()
    {
        return this->top;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node(data);
        this->size++;
        if (this->isEmpty())
        {
            this->top = newNode;
        }
        newNode->next = this->top;
        this->top = newNode;
    }

    void pop()
    {
        if (this->isEmpty())
            throw std::invalid_argument("Stack is empty");
        Node<T> *temp = this->top;
        this->top = temp->next;
        this->size--;
        delete (temp);
    }

    bool isEmpty()
    {
        if (this->top == NULL)
            return true;
        return false;
    }

    void clear()
    {
        Node<T> *temp = this->top;
        this->top = NULL;
        this->size = 0;
        delete (temp);
    }

    std::string toString()
    {
        if (this->isEmpty())
            return "[]";
        Node<T> *temp = this->top;
        std::string msg = this->convertToString(temp->data);
        temp = temp->next;
        while (temp)
        {
            msg += " " + this->convertToString(temp->data);
            temp = temp->next;
        }
        return msg;
    }
};