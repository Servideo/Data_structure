#include<iostream>
#include <vector>
using std::vector,std::cout;
template<typename T>
void print(vector<T> itr){
    for(int i = 0;i < itr.size();i++) cout << itr[i] <<" ";
    cout<<"\n";
};