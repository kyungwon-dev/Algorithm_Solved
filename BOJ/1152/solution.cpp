#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    istringstream iss(str);
    string token;
    int count=0;
    while(getline(iss, token, ' ')){
        if(token.size()==0)
            continue;
        count++;
    }
    cout << count << "\n";

    return 0;
}