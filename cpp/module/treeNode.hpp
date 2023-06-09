#pragma once
#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode
{
public:
    TreeNode<T> *rightChild, *leftChild;
    T data;
    TreeNode(T data)
    {
        this->data = data;
        this->rightChild = nullptr;
        this->leftChild = nullptr;
    }
    ~TreeNode() {}
};

#endif
