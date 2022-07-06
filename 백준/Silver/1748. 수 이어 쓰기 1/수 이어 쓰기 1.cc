#include <iostream>
#include <vector>
#include <string>
using namespace std;


void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    long long n, answer = 0, j, i;
    cin >> n;
    string str = to_string(n);
    for(i=1,j=1;j<str.length();i*=10,j++){
        // cout << ( (i*10-1) - (i) +1) * j << "\n"; 
        answer += ( (i*10-1) - (i) +1) * j;
    }
    //cout << (n-i+1) * j << "\n";
    answer += (n - i + 1) * j;
    cout << answer << "\n";
    return 0;
}