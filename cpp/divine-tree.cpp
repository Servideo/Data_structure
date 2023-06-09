#include <iostream>
#include <string>
#include <vector>
#include "./module/BinaryTree.hpp"
#include "./module/treeNode.hpp"
#include "./module/node.hpp"
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

int sumList(LinkedList<int> &llist)
{
    int sum = 0;
    Node<int> *temp = llist.get(0);
    while (temp != nullptr)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int divineTree(BinaryTree<int> &tree)
{
    LinkedList<int> viewLevel;
    TreeNode<int> *root = tree.getRoot();
    int maxNumber = root->data;
    int temp = 0;
    int sizeTree = tree.levelOfTree(root);
    for (int level = 1; level <= sizeTree; level++)
    {
        tree.viewLevel(root, level, viewLevel);
        temp = sumList(viewLevel);
        if (temp > maxNumber) maxNumber = temp;
        viewLevel.clear();
    }
    return maxNumber;
}

void showLevel(BinaryTree<int> &tree)
{
    LinkedList<int> viewLevel;
    TreeNode<int> *root = tree.getRoot();
    int sizeTree = tree.levelOfTree(root);
    for (int level = 0; level <= sizeTree; level++)
    {
        tree.viewLevel(root, level, viewLevel);
        std::cout << "\n" << "nivel " << level << ":\n" << viewLevel.toString() << "\n";
        viewLevel.clear();
    } 
}

int main()
{
    BinaryTree<int> tree;
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> number = split(input);
    tree.createTree(number);
    int sumLevel = divineTree(tree);
    std::cout << "sumatoria mas alta: " << sumLevel;
    showLevel(tree);
    return 0;
}
