#include "node.h"
#include <sstream>
#include <string>
using std::stringstream, std::string;

template <class T>
class Queque
{
private:
    Node<T> *front, *rear;
    int maxSize;
    int size;
    string convertToString(T data)
    {
        stringstream text;
        text << data;
        return text.str();
    }

public:
    Queque<T>(int maxSize = 0)
    {
        this->front = this->rear = NULL;
        this->size = 0;
        this->maxSize = maxSize;
    }

    Node<T>* getFront()
    {
        if(this->isEmpty())
            return NULL;
        return this->front;
    }

    Node<T>* getBack()
    {
        if(this->isEmpty())
            return NULL;
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
        if(maxSize < this->maxSize) return;
        this->maxSize = maxSize;
    }
    bool isEmpty()
    {
        if (this->front == NULL)
            return true;
        return false;
    }

    void enqueue(T data)
    {
        if(this->maxSize > 0 && this->size >= this->maxSize)
            return;
        Node<T> *temp = new Node(data);
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
            return;
        Node<T> *temp = this->front;
        this->size--;
        this->maxSize--;
        this->front = this->front->next;

        if (this->front == NULL)
            this->rear == NULL;
        delete (temp);
    }

    void clear()
    {
        Node<T> *temp = this->front;
        this->front = this->rear = NULL;
        this->size = this->maxSize = 0;
        delete(temp);
    }
    
    string toString()
    {
        if (this->isEmpty())
            return "[]";
        Node<T> *temp = this->front;
        string msg = "["+this->convertToString(temp->data);
        temp = temp->next;
        while (temp)
        {
            msg += " " + this->convertToString(temp->data);
            temp = temp->next;
        }
        msg +="]";
        return msg;
    }
};