#include <iostream>
#include <string>
#include "./module/linkedlist.hpp"

LinkedList<int> split(std::string text, std::string sep=" ")
{
    LinkedList<int> number;
    int start = 0;
    int end = text.find(sep);
    while(end != -1)
    {
        number.add(std::stoi(text.substr(start, end)));
        start = end + sep.size();
        end = text.find(sep, start);
    }
    number.add(std::stoi(text.substr(start)));
    return number;
}
void removeCommon(LinkedList<int>& llist1, LinkedList<int>& llist2)
{
    int index1 = 0;
    int index2 = llist2.getSize() - 1;
    while(index1 < llist1.getSize() && index2 >= 0)
    {
        if(index1 == 0 && llist1.get(index1)->data == llist2.get(index2)->data){
            llist1.pop(index1);
            llist2.pop(index2);
            index2 = llist2.getSize() - 1;
            continue;
        }
        else if(llist1.get(index1)->data == llist2.get(index2)->data){
            llist1.pop(index1);
            llist2.pop(index2);
            index1--;
            continue;
        }
        index1++;
        index2--;
    }
}

int main()
{
    std::string input1;
    std::getline(std::cin, input1);
    LinkedList<int> lnumber1 = split(input1);
    input1 = "";
    std::getline(std::cin, input1);
    LinkedList<int> lnumber2 = split(input1);
    removeCommon(lnumber1, lnumber2);
	std::cout<<lnumber1.toString() <<"\n"<<lnumber2.toString();
    return 0;
}