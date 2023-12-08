#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for(auto &c : myString){
        if(c == 'a')
            c = 'A';
        else if(c == 'A') continue;
        else
            c = tolower(c);
    }
    return myString;
}