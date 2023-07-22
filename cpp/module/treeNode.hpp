#pragma once
#ifndef TREENODE_HPP
#define TREENODE_HPP

template <class T>
class TreeNode
{
public:
    TreeNode<T> *rightChild = nullptr;
    TreeNode<T> *leftChild = nullptr;
    T data;
    TreeNode(T data) : data(data)
    {
    }
    ~TreeNode() {}
};

#endif
