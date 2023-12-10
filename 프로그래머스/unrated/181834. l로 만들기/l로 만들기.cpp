#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto &str : myString){
        if(str < 'l'){
            str = 'l';
        }
    }
    return myString;
}