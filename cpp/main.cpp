#include <iostream>
#include <string>
#include "./module/linkedlist.h"
using namespace std;
int main()
{
    // LinkedList<int> number;
    LinkedList<string> person;
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
    // number.printlist();
    cout << "Escribe algunos nombres" << endl;
    for (int i = 0; i < 6; i++)
    {
        string fName;
        getline(cin, fName);
        person.add(fName);
    }
    cout << "elementos de la lista: "<<person.toString()<<endl;
    cout << "ultima posicion: " << person.get(person.getSize() - 1) << endl;
    person.reverse();
    cout << "lista invertida de personas: "<<person.toString()<<endl;
    cout << "ultima posicion: " << person.get(person.getSize() - 1) << endl;
    return 0;
}