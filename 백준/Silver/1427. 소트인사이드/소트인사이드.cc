#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
    
int main(){
    init();
    string str;
    cin >> str;
    sort(str.begin(),str.end(),greater<>());
    cout << str << "\n";
    return 0;
}