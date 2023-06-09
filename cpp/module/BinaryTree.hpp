#pragma once
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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
    TreeNode<T> *root;

public:
    BinaryTree()
    {
        this->root = nullptr;
    }
    ~BinaryTree() {}

    TreeNode<T> *getRoot()
    {
        return this->root;
    }

    void insertValue(T data)
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

    void traversePreOrder(TreeNode<T> *temp, std::vector<T> &array)
    {
        if (!temp)
            return;
        array.push_back(temp->data);
        this->traversePreOrder(temp->leftChild, array);
        this->traversePreOrder(temp->rightChild, array);
    }

    std::vector<T> preOrder()
    {
        if (this->isEmpty)
            throw std::invalid_argument("tree is empty");
        std::vector<T> array;
        this->traversePreOrder(this->root, array);
    }

    LinkedList<T> inOrder()
    {
        if(this->isEmpty()) throw std::invalid_argument("Tree empty");
        LinkedList<T> llist;
        Stack<TreeNode<T> *> stack;
        TreeNode<T> * current = this->root;
        while (!stack.isEmpty() || current)
        {
            if (current)
            {
                stack.push(current);
                current = current->leftChild;
            }

            current = stack.peek()->data;
            stack.pop();
            llist.add(current->data);
            current = current->rightChild;
        }
        return llist;
    }

    std::vector<T> levelOrder()
    {
        if(this->isEmpty()) throw std::invalid_argument("Tree empty");
        Queque<TreeNode<T> *> queue;
        std::vector<T> array;
        queue.enqueue(this->root);
        while (!queue.isEmpty())
        {
            TreeNode<T> *temp = queue.getFront()->data;
            array.push_back(temp->data);
            if (temp->leftChild)
                queue.enqueue(temp->leftChild);
            if (temp->rightChild)
                queue.enqueue(temp->rightChild);
            queue.dequeue();
        }
    }

    void postOrder(TreeNode<T> *temp, std::vector<T> &array)
    {
        if (!temp)
            return;
        this->postOrder(temp->leftChild, array);
        this->postOrder(temp->rightChild, array);
        array.push_back(temp->data);
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

    void viewLevel(TreeNode<T> *node, int level, LinkedList<T> &llist)
    {
        if (node == nullptr)
            return;
        if (level == 0)
            llist.add(node->data);
        this->viewLevel(node->leftChild, level - 1, llist);
        this->viewLevel(node->rightChild, level - 1, llist);
    }
};
#endif