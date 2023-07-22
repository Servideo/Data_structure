#pragma once
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <vector>
#include <sstream>

#include "treeNode.hpp"
#include "Queque.hpp"
#include "linkedlist.hpp"
#include "Stack.hpp"

template <class T>
class BinaryTree
{
private:
    TreeNode<T> *root = nullptr;

    int levelOfTree(TreeNode<T> *node)
    {
        if (node == nullptr)
            return 0;
        else if (node->leftChild == node->rightChild && node->leftChild == nullptr)
            return 0;
        int left = this->levelOfTree(node->leftChild) + 1;
        int right = this->levelOfTree(node->rightChild) + 1;
        if (left > right)
            return left;
        return right;
    }

    void recursivePreOrder(TreeNode<T> *temp, std::vector<T> &array)
    {
        if (temp != nullptr)
        {
            array.push_back(temp->data);
            this->recursivePreOrder(temp->leftChild, array);
            this->recursivePreOrder(temp->rightChild, array);
        }
    }

    void recursiveInOrder(TreeNode<T> *temp, std::vector<T> &array)
    {
        if (temp != nullptr)
        {
            this->recursiveInOrder(temp->leftChild, array);
            array.push_back(temp->data);
            this->recursiveInOrder(temp->rightChild, array);
        }
    }

    void recursivePostOrder(TreeNode<T> *temp, std::vector<T> &array)
    {
        if (temp != nullptr)
        {
            this->recursivePostOrder(temp->leftChild, array);
            this->recursivePostOrder(temp->rightChild, array);
            array.push_back(temp->data);
        }
    }

    void viewLevel(TreeNode<T> *node, int level, LinkedList<T> &llist)
    {
        if (node == nullptr)
            return;
        if (level == 0)
            llist.add(node->data);
        this->viewLevel(node->leftChild, level - 1, llist);
        this->viewLevel(node->rightChild, level - 1, llist);
    }

public:
    BinaryTree() {}
    ~BinaryTree() {}

    TreeNode<T> *getRoot() const
    {
        return this->root;
    }

    void insertValue(const T data)
    {
        TreeNode<T> *newData = new TreeNode<T>(data);
        if (this->isEmpty())
        {
            this->root = newData;
            return;
        }
        Queque<TreeNode<T> *> tree;
        tree.enqueue(this->root);

        while (!tree.isEmpty())
        {
            TreeNode<T> *temp = tree.getFront()->data;
            tree.dequeue();
            if (!temp->leftChild)
            {
                temp->leftChild = newData;
                return;
            }
            else
                tree.enqueue(temp->leftChild);
            if (!temp->rightChild)
            {
                temp->rightChild = newData;
                return;
            }
            else
                tree.enqueue(temp->rightChild);
        }
    }

    void createTree(std::vector<T> array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            this->insertValue(array[i]);
        }
    }

    std::vector<T> recursivePreOrder()
    {
        if (this->isEmpty())
            throw std::invalid_argument("tree is empty");
        std::vector<T> array;
        this->recursivePreOrder(this->root, array);
        return array;
    }

    std::vector<T> PreOrder()
    {
        if (this->isEmpty())
            throw std::invalid_argument("tree is empty");
        std::vector<T> array;
        Stack<TreeNode<T> *> stack;
        TreeNode<T> *current = this->root;
        stack.push(current);
        while (!stack.isEmpty())
        {
            if (current != nullptr)
            {
                array.push_back(current->data);

                if (current->rightChild != nullptr)
                    stack.push(current->rightChild);
                current = current->leftChild;
            }
            else
            {
                current = stack.peek()->data;
                stack.pop();
            }
        }
        return array;
    }

    std::vector<T> recursiveInOrder()
    {
        if (this->isEmpty())
            throw std::invalid_argument("Tree empty");
        std::vector<T> array;
        this->recursiveInOrder(this->root, array);
        return array;
    }

    std::vector<T> inOrder()
    {
        if (this->isEmpty())
        {
            throw std::invalid_argument("Tree is empty");
        }
        std::vector<T> llist;
        Stack<TreeNode<T> *> stack;
        TreeNode<T> *current = this->root; 
        while(true)
        {
            if (current != nullptr)
            {
                stack.push(current);
                current = current->leftChild;
            }
            else
            {
                if (stack.isEmpty())
                {
                    break;
                }
                current = stack.peek()->data;
                stack.pop();
                llist.push_back(current->data);
                current = current->rightChild;
            }
        }

        return llist;
    }

    std::vector<T> levelOrder()
    {
        if (this->isEmpty())
            throw std::invalid_argument("Tree empty");
        Queque<TreeNode<T> *> queue;
        std::vector<T> array;
        queue.enqueue(this->root);
        while (!queue.isEmpty())
        {
            TreeNode<T> *temp = queue.getFront()->data;
            array.push_back(temp->data);
            if (temp->leftChild != nullptr)
                queue.enqueue(temp->leftChild);
            if (temp->rightChild != nullptr)
                queue.enqueue(temp->rightChild);
            queue.dequeue();
        }
        return array;
    }

    std::vector<T> recursivePostOrder()
    {
        if (this->isEmpty())
        {
            throw std::invalid_argument("Tree empty");
        }
        std::vector<T> array;
        this->recursivePostOrder(this->root, array);
        return array;
    }

    std::vector<T> postOrder()
    {
        if (this->isEmpty())
        {
            throw std::invalid_argument("Tree empty");
        }
        std::vector<T> array;
        Stack<TreeNode<T> *> prevStack;
        Stack<TreeNode<T> *> currentStack;
        TreeNode<T> *current = this->root;
        prevStack.push(current);
        while (!prevStack.isEmpty())
        {
            current = prevStack.peek()->data;
            currentStack.push(current);
            prevStack.pop();
            if (current->leftChild != nullptr)
            {
                prevStack.push(current->leftChild);
            }
            if (current->rightChild != nullptr)
            {
                prevStack.push(current->rightChild);
            }
        }
        while (!currentStack.isEmpty())
        {
            current = currentStack.peek()->data;
            array.push_back(current->data);
            currentStack.pop();
        }
        return array;
    }

    bool isEmpty()
    {
        return (this->root == nullptr) ? true : false;
    }

    void clear()
    {
        TreeNode<T> *temp = this->root;
        this->root = nullptr;
        delete temp;
    }

    int high()
    {
        if (this->isEmpty())
        {
            throw std::invalid_argument("Tree empty");
        }
        return this->levelOfTree(this->root) + 1;
    }

    LinkedList<T> viewLevel(int level)
    {
        if (this->isEmpty())
        {
            throw std::invalid_argument("Tree empty");
        }
        LinkedList<T> llist;
        this->viewLevel(this->root, level, llist);
        return llist;
    }

    TreeNode<T> *search(T key)
    {
        if (this->isEmpty())
        {
            throw std::invalid_argument("Arbol vacio.");
        }
        else if (this->root->leftChild == nullptr && this->root->rightChild == nullptr)
        {
            if (this->root->data == key)
            {
                return this->root;
            }
            else
            {
                throw std::invalid_argument("Elemento no encotrado."); 
            }
        }
        TreeNode<T> *current = nullptr;
        Queque<TreeNode<T> *> queue;
        queue.enqueue(this->root);
        while(!queue.isEmpty())
        {
            current = queue.getFront()->data;
            queue.dequeue();
            if (current->data == key)
            {
                return current;
            }
            if (current->leftChild)
            {
                queue.enqueue(current->leftChild);
            }
            if (current->rightChild)
            {
                queue.enqueue(current->rightChild);
            }
        }
        if (current == nullptr)
        {
            throw std::invalid_argument("Elemento no encotrado.");
        }
    }

    void deleteNode(T key)
    {
        if (this->isEmpty())
        {
            throw std::invalid_argument("Arbol vacio.");
        }
        else if (this->root->leftChild == nullptr && this->root->rightChild == nullptr)
        {
            if (this->root->data == key)
            {
                this->root == nullptr;
                return;
            }
            else
            {
                throw std::invalid_argument("Elemento no encotrado."); 
            }
        }

        TreeNode<T> *current = nullptr;
        TreeNode<T> *last = nullptr;
        TreeNode<T> *target = nullptr;
        Queque<TreeNode<T> *> queue;
        queue.enqueue(this->root);

        while(!queue.isEmpty())
        {
            current = queue.getFront()->data;
            queue.dequeue();
            if (current->data == key)
            {
                target = current;
            }
            if (current->leftChild)
            {
                last = current;
                queue.enqueue(current->leftChild);
            }
            if (current->rightChild)
            {
                last = current;
                queue.enqueue(current->rightChild);
            }
        }
        if (target != nullptr)
        {
            target->data = current->data;
            if (last->leftChild == current)
            {
                last->leftChild = nullptr;
            }
            else
            {
                last->rightChild = nullptr;
            }
            delete current;
        }
        else
        {
            throw std::invalid_argument("Elemento no encotrado.");
        }
    }


};
#endif