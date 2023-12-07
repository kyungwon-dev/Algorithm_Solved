#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string myString, string pat) {
    for(int i=0;i<myString.size();i++){
        myString[i] = myString[i] > 'Z' ? myString[i]: myString[i] + 'a' - 'A' ;
    }
    for(int i=0;i<pat.size();i++){
        pat[i] = pat[i] > 'Z' ? pat[i]: pat[i] + 'a' - 'A' ;
    }
    if(myString.find(pat) == string::npos) return 0;
    return 1;
}