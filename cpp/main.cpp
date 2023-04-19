#include <iostream>
#include <string>
#include "./module/linkedlist.h"
using namespace std;
int main()
{
    LinkedList<int> number;

    number.add(8);
    number.add(7);
    number.add(5);
    number.add(3);
    cout << "valor en la posicion 2: " << number.get(2) << endl;
    cout << "elementos de la lista: ";
    number.printlist();
    LinkedList<string> person;
    person.add("pepe sanchez");
    person.add("Antonio Vandera");
    person.add("Emiliano Rodriguez");
    person.add("Anamaria Peña");
    person.add("Alfonso Pelaez");
    cout << "elementos de la lista: ";
    person.printlist();
    cout << "posicion 1: " << person.get(1) << endl;
    return 0;
}