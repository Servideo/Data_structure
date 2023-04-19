#include "./module/linkedlist.h"
#include "./module/split.h"
#include "./module/printvector.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    LinkedList<string> llexpo;
    string input;
    getline(cin, input);
    vector<string> lperson = split(input);
    int count1;
    int count2 = lperson.size() - 1;
    bool flag = false;
    while (count1 <= count2)
    {
        if (flag)
        {
            llexpo.add(lperson[count2]);
            count2--;
            flag = false;
            continue;
        }
        llexpo.add(lperson[count1]);
        count1++;
        flag = true;
    }
    llexpo.printlist();
    return 0;
}