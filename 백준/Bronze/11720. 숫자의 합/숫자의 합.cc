#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int N, sum=0;
    cin >> N >> str;
    for(int i=0;i<N;i++)
        sum += str[i]-'0';
    cout << sum << "\n";
    return 0;
}