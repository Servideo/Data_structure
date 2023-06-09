#include <iostream>
#include <vector>
#include <string>
#include "./module/BinaryTree.hpp"

std::vector<int> split(std::string str, std::string sep=" ")
{
    std::vector<int> array;
    int start = 0;
    int end = str.find(sep);
    while(end != -1)
    {
        array.push_back(std::stoi(str.substr(start, end)));
        start = end + sep.size();
        end = str.find(sep,start);
    }
    array.push_back(std::stoi(str.substr(start, end)));
    return array;
}

void searchBestRoute(BinaryTree<int>& temp, int numberNode)
{
    int countByPreOrder = 0;
    int countByInOrder = 0;
    int countByPostOrder = 0;
    std::vector<int> preOrder;
    std::vector<int> inOrder;
    std::vector<int> postOrder;
    temp.preOrder(temp.getRoot(), preOrder);
    temp.inOrder(temp.getRoot(), inOrder);
    temp.postOrder(temp.getRoot(), postOrder);
    for (int i = 0; i < numberNode; i++)
    {
        countByPreOrder += preOrder[i];
        countByInOrder += inOrder[i];
        countByPostOrder += postOrder[i];
    }
    if(countByPreOrder >= countByInOrder && countByPreOrder >= countByPostOrder){
        std::cout << "Preorder "<< countByPreOrder;
        return;
    }else if(countByInOrder >= countByPreOrder && countByInOrder >= countByPostOrder){
        std::cout << "Inorder "<< countByInOrder;
        return;
    }else if(countByPostOrder >= countByInOrder && countByPostOrder >= countByPreOrder){
        std::cout << "Postorder "<< countByPostOrder;
        return;
    }
    std::cout << "Preorder "<< countByPreOrder;
}

int main()
{
    BinaryTree<int> number;
    std::string place;
    int numberNode;
    std::getline(std::cin,place);
    std::vector<int> places = split(place);
    scanf("%d",&numberNode);
    number.createTree(places);
    searchBestRoute(number, numberNode);
    return 0;
}