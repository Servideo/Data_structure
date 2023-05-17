#include <iostream>
#include <string>
#include "./module/linkedlist.h"
using namespace std;

LinkedList<string> split(string text,string sep=" ")
{
    LinkedList<string> llist;
    int start = 0;
    int end = text.find(sep);
    while (end != -1){
        llist.add(text.substr(start, end - start));
        start = end + sep.size();
        end = text.find(sep, start);
    };
    llist.add(text.substr(start));
    return llist;
}

void ordenExpo(LinkedList<string>& llist1,LinkedList<string>& llist2)
{
    int index1 = 0;
    int index2 = llist1.getSize() - 1;
    bool changeIndex = false;
    while (index1 <= index2)
    {
        if (changeIndex)
        {
            llist2.add(llist1.get(index2)->data);
            index2--;
            changeIndex = false;
            continue;
        }
        llist2.add(llist1.get(index1)->data);
        index1++;
        changeIndex = true;
    }
}

int main(){
    string name;
    LinkedList<string> expo;
    getline(cin, name);
    LinkedList<string> person = split(name);
    ordenExpo(person, expo);
    cout << expo.toString();    
    return 0;
}


