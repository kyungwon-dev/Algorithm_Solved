#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    for(auto &str : myString){
        if(str == 'A')
            str = 'B';
        else
            str = 'A';
    }
    if(myString.find(pat) == string::npos) return 0;
    return 1;
}