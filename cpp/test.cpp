#include <iostream>
#include <string>
#include "./module/dblinkedlist.h"

using namespace std;

int main()
{
    DoublyLinkedList<int> number;
    number.add(1);
    number.add(2);
    number.add(3);
    number.add(4);
    number.add(6);
    cout <<"Lista: "<< number.toString() << endl;
    cout <<"tamaño: "<< number.getSize() << endl;
    number.reverse();
    cout <<"Lista: "<< number.toString() << endl;
    try{
        number.pop(0);
    }catch(exception &e){
        cout << e.what() << endl;
    }
    number.add(5);
    cout <<"Lista: "<< number.toString() << endl;
    number.reverse();
    cout <<"Lista: "<< number.toString() << endl;
    return 0;
}