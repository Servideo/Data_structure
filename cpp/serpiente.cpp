#include <iostream>
#include <vector>
#include <string>
#include "./module/node.hpp"
#include "./module/BinaryTree.hpp"
#include "./module/treeNode.hpp"
#include "./module/Stack.hpp"
#include "./module/linkedlist.hpp"

std::vector<int> split(std::string text, std::string sep = " ")
{
    std::vector<int> llist;
    int start = 0;
    int end = text.find(sep);
    while (end != -1)
    {
        int subtring = std::stoi(text.substr(start, end));
        llist.push_back(subtring);
        start = end + sep.size();
        end = text.find(sep, start);
    }
    int subtring = std::stoi(text.substr(start));
    llist.push_back(subtring);
    return llist;
}

int traversalStack(Stack<int> &stack, bool &flag)
{
    int sum = 0;
    Node<int> *temp;
    temp = stack.peek();
    while(temp != nullptr)
    {
        if(flag)
        {
            sum += temp->data;
            flag = false;
            temp = temp->next;
            continue;
        }
        temp = temp->next;
        flag = true;
    }
    return sum;
}

int traversalLinkedList(LinkedList<int> &llist, bool &flag)
{
    int sum = 0;
    Node<int> *temp;
    temp = llist.get(0);
    while(temp != nullptr)
    {
        if(flag)
        {
            sum += temp->data;
            temp = temp->next;
            flag = false;
            continue;
        }
        temp = temp->next;
        flag = true;
    }
    return sum;
}

void viewLevelStack(TreeNode<int> *node, int level, Stack<int> &stack)
{
    if (node == nullptr) return;
    if (level == 0) stack.push(node->data);
    viewLevelStack(node->leftChild, level - 1, stack);
    viewLevelStack(node->rightChild, level - 1, stack);
}

void snakeTravel(BinaryTree<int> &treeNumber, int &minimunCalories)
{
    TreeNode<int> *root = treeNumber.getRoot();
    Stack<int> zap;
    LinkedList<int> temp;
    int foodCount = root->data;
    if(foodCount >= minimunCalories)
    {
        std::cout << "Sobrevive";
        return;    
    }

    int maxLevel = treeNumber.levelOfTree(root);
    bool swap = true;
    bool sum = false;

    for (int level = 1; level <= maxLevel; level ++)
    {
        if(swap)
        {
            viewLevelStack(root, level, zap);
            foodCount += traversalStack(zap, sum);
            swap = false;
            zap.clear();
        }else
        {
            treeNumber.viewLevel(root, level, temp);
            foodCount += traversalLinkedList(temp, sum);
            swap = true;
            temp.clear();
        }
        if(foodCount >= minimunCalories)
        {
        std::cout << "Sobrevive";
        return;    
        } 
    }
    std::cout << "Muere";

}


int main()
{
    BinaryTree<int> tree;
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> number = split(input);
    input = "";
    std::cin >> input;
    int minimunCalories = std::stoi(input);
    tree.createTree(number);
    snakeTravel(tree, minimunCalories);
    return 0;
}