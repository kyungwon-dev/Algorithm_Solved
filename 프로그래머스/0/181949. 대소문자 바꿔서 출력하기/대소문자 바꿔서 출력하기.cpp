#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(auto s : str){
        if('A' <= s && s <= 'Z')
            cout << (char)(s - 'A' + 'a');
        else
            cout << (char)(s - 'a' + 'A');
    }
    return 0;
}