#include <iostream>
#include <string>
#include "./module/linkedlist.hpp"
using namespace std;
int main()
{
    LinkedList<int> number;
    number.add(1);
    number.add(2);
    number.add(3);
    number.add(4);
    cout << number.toString() << endl;
    number.pop(2);
    cout << number.toString() << endl;
    // LinkedList<string> person;
    // cout<<"Escribe algunos numeros"<<endl;
    // for (int i = 0; i < 6; i++)
    // {
    //     string element;
    //     cin >> element;
    //     number.add(stoi(element));
    // }

    // cout << "valor en la posicion 2: " << number.get(2) << endl;
    // cout << "elementos de la lista: number.toString()"<<endl;
    // number.reverse();
    // cout << "lista invertida de numeros: ";
    // cout << number.toString() endl;
    // cout << "Escribe algunos nombres" << endl;
    // for (int i = 0; i < 6; i++)
    // {
    //     string fName;
    //     getline(cin, fName);
    //     person.add(fName);
    // }
    // cout << "elementos de la lista: "<<person.toString()<<endl;
    // cout << "ultima posicion: " << person.get(person.getSize() - 1) << endl;
    // person.reverse();
    // cout << "lista invertida de personas: "<<person.toString()<<endl;
    // cout << "ultima posicion: " << person.get(person.getSize() - 1) << endl;
    return 0;
}