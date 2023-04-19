#include "node.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
    // Atributos
    Node<T> *head;
    Node<T> *last;
    int size;

public:
    // constructor
    LinkedList<T>()
    {
        head = NULL;
        last = NULL;
        size = 0;
    }
    // getter
    T get(int index)
    {
        if (index == 0)
            return this->head->data;
        else if (index == size - 1)
            return this->last->data;
        Node<T> *current = this->head->next;
        for (int i = 1; i < index; i++)
            current = current->next;
        return current->data;
    }
    int getSize()
    {
        return size;
    }
    // metodos
    void add(T data)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            head->next = last;
            size++;
            return;
        }
        else if (last == NULL)
        {
            last = newNode;
            head->next = last;
            last->next = NULL;
            size++;
            return;
        }
        last->next = newNode;
        last = newNode;
        last->next = NULL;
        size++;
    }
    void printlist()
    {
        if (head == NULL)
            return;
        Node<T> *temp = head;
        cout << temp->data;
        temp = temp->next;
        while (temp)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
        cout << "\n";
    }
};