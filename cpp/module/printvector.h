#include<iostream>
#include <vector>
using namespace std;
template<typename T>
void print(vector<T> itr){
    for(int i = 0;i < itr.size();i++) cout << itr[i] <<" ";
    cout<<endl;
};