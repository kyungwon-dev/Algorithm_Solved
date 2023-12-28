#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString, string pat) {
    string subMyString = "";
    while(myString.find(pat) != string::npos){
        subMyString += myString.substr(0,myString.find(pat) + pat.size());
        myString = myString.substr(myString.find(pat) + pat.size());
    }
    return subMyString;
}