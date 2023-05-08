#include "./module/Queque.h"
#include <string>
#include <iostream>

using namespace std;

Queque<string> split(string text, string separator = " ", int limit = 0)
{
    Queque<string> result(limit);
    int start = 0;
    int end = text.find(separator);
    while (end != -1)
    {
        result.enqueue(text.substr(start, end - start));
        start = end + separator.size();
        end = text.find(separator, start);
    }
    result.enqueue(text.substr(start, end - start));
    return result;
}

string input()
{
    string msg = "";
    getline(cin, msg);
    return msg;
}

Queque<string> insertQueque()
{
    string element;
    int iter;
    iter = stoi(input());
    element = input();
    Queque<string> queue = split(element, " ", iter);
    return queue;
}

string deliveryAtSmall(Queque<string> &product, Queque<string> &numberProduct)
{
    string reportOfSmall = "";
    int numberofDeliveries = numberProduct.getSize();
    for (int i = 0; i < numberofDeliveries; i++)
    {
        int numberOfDelivery = stoi(numberProduct.getFront()->data);
        Queque<string> small(numberOfDelivery);
        if (product.getSize() == 0)
        {
            if (i == 0)
            {
                reportOfSmall += small.toString();
                break;
            }
            reportOfSmall += "\n" + small.toString();
            continue;
        }
        for (int j = 0; j < numberOfDelivery; j++)
        {
            if (product.getSize() == 0)
                break;
            small.enqueue(product.getFront()->data);
            product.dequeue();
        }
        if (i == 0)
        {
            reportOfSmall += small.toString();
            numberProduct.dequeue();
            continue;
        }
        reportOfSmall += "\n" + small.toString();
        numberProduct.dequeue();
    }
    return reportOfSmall;
}

string deliverySystem(string numberCase)
{
    string reporDelivery = "";
    int round = stoi(numberCase);
    for (int i = 0; i < round; i++)
    {
        Queque<string> goods = insertQueque();
        Queque<string> numberOfSmalls = insertQueque();
        reporDelivery += deliveryAtSmall(goods, numberOfSmalls);
        goods.clear();
        numberOfSmalls.clear();
        if (round > 1 && i < round - 1)
        {
            reporDelivery += "\n";
        }
    }
    return reporDelivery;
}

int main(int argc, const char *argv[])
{
    string numberCase;
    getline(cin, numberCase);
    cout << deliverySystem(numberCase);
    return 0;
}