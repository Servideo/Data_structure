#include <cstddef>

template <class T>
struct Node{
    public:
    Node *prev, *next;
    T data;
    Node(T data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};