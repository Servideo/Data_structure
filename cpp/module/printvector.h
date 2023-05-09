#include<iostream>
#include <vector>
template<typename T>
void print(std::vector<T> itr){
    for(int i = 0;i < itr.size();i++) cout << itr[i] <<" ";
    std::cout << "\n";
};