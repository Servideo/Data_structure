#include <string>
#include <vector>

vector<string> split(string text, string sep = " ")
{
    vector<string> element;
    int start = 0;
    int end = text.find(sep);
    
    while (end != -1){
        element.push_back(text.substr(start, end - start));
        start = end + sep.size();
        end = text.find(sep, start);
    };
    element.push_back(text.substr(start, end - start));
    return element;
}