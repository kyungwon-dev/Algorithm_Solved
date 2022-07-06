#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    string rs = "";
    if(str1.length() > str2.length()){
        string tmp(str1.length() - str2.length(),'0');
        str2 = tmp + str2;
    }
    else{
        string tmp(str2.length() - str1.length(),'0');
        str1 = tmp + str1;
    }
    int over = 0;
    for(int i=str1.size()-1;i>=0;i--){
        int a = str1[i] - '0';
        int b = str2[i] - '0';
        rs.push_back( '0' + ( (a+b+over) % 10));
        if(a+b+over>=10) over = 1;
        else over = 0;
    }
    if(over == 1)
        rs.push_back('1');
    reverse(rs.begin(),rs.end());
    cout << rs << "\n";
    return 0;
}