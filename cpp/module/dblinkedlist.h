#include "node.h"
#include <string>
#include <sstream>
template <class T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

    std::string convertoString(T data)
    {
        std::stringstream text;
        text << data;
        return text.str();
    }

public:
    DoublyLinkedList<T>()
    {
        this->head = this->tail = NULL;
        this->size = 0;
    }

    T get(int index)
    {
        if (this->isEmpty())
            return 0;
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
        Node<T>* newNode = new Node(data);
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
        if(this->isEmpty() || index >= this->size)
            return;
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
    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        if (this->head == NULL)
            return true;
        return false;
    }

    void clear()
    {
        this->head = this->tail = NULL;
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