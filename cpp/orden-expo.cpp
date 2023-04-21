#include "./module/linkedlist.h"
#include "./module/split.h"
#include "./module/printvector.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
void ordenExpo(vector<T> array, LinkedList<T>& llist);

int main()
{
    LinkedList<string> llexpo;
    string input;
    getline(cin, input);
    vector<string> lperson = split(input);
    ordenExpo<string>(lperson, llexpo);
    cout << llexpo.toString()<<endl;
    return 0;
}


template<typename T>
void ordenExpo(vector<T> array,LinkedList<T>& llist){
    int count1 = 0;
    int count2 = array.size() - 1;
    bool flag = false;
    while (count1 <= count2)
    {
        if (flag)
        {
            llist.add(array[count2]);
            count2--;
            flag = false;
            continue;
        }
        llist.add(array[count1]);
        count1++;
        flag = true;
    }
}