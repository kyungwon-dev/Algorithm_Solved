#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    cin >> str;
    int sum = str.length();
    for(auto ch : str){
        if(ch <= 'C')
            sum += 2;
        else if(ch <= 'F')
            sum += 3;
        else if(ch <= 'I')
            sum += 4;
        else if(ch <= 'L')
            sum += 5;
        else if(ch <= 'O')
            sum += 6;
        else if(ch <= 'S')
            sum += 7;
        else if(ch <= 'V')
            sum += 8;
        else
            sum += 9;
    }
    cout << sum << "\n";

    return 0;
}