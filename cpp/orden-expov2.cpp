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
        llist.add(text.substr(start, end));
        start = end + sep.size();
        end = text.find(sep, start);
    };
    llist.add(text.substr(start, end));
    // llist.add(text.substr(start, end - start));
    return llist;
}

void ordenExpo(LinkedList<string>& llist1,LinkedList<string>& llist2)
{
    int count1 = 0;
    int count2 = llist1.getSize() - 1;
    bool flag = false;
    while (count1 <= count2)
    {
        if (flag)
        {
            llist2.add(llist1.get(count2));
            count2--;
            flag = false;
            continue;
        }
        llist2.add(llist1.get(count1));
        count1++;
        flag = true;
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


