#include "./module/linkedlist.hpp"
#include <string>
#include <iostream>

using namespace std;

LinkedList<int> split(string text, string sep = " ")
{
    LinkedList<int> llist;
    int start = 0;
    int end = text.find(sep);
    while (end != -1)
    {
        llist.add(stoi(text.substr(start, end)));
        start = end + sep.size();
        end = text.find(sep, start);
    }
    llist.add(stoi(text.substr(start, end)));
    return llist;
}

void dayToSell(LinkedList<int> &source)
{
    LinkedList<int> llist = source;
    LinkedList<int> llday;
    int count;
    int maximunSize = source.getSize();
    int limit = llist.getSize();
    for (int i = 0; i < maximunSize; i++)
    {
        count = 0;
        if (limit - 1 == 0)
        {
            llday.add(count);
            break;
        }
        for (int j = 1; j < limit; j++)
        {
            if (llist.get(0)->data > llist.get(j)->data && j != limit - 1)
            {
                count++;
                continue;
            }
            else if (llist.get(j)->data > llist.get(0)->data)
            {
                count++;
                break;
            }
            else if (j == limit - 1 && llist.get(0)->data > llist.get(j)->data)
            {
                count = 0;
                break;
            }
            else if (j == limit - 1 && llist.get(0)->data == llist.get(j)->data)
            {
                count = 0;
                break;
            }
            count++;
        }
        llday.add(count);
        llist.pop(0);
        limit = llist.getSize();
    }
    cout << llday.toString();
}

int main()
{
    string text;
    LinkedList<int> llnumber;
    getline(cin, text);
    llnumber = split(text);
    dayToSell(llnumber);
    return 0;
}