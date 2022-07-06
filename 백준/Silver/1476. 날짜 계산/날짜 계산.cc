#include <iostream>

using namespace std;

int main(){
    int E, S, M;
    cin >> E >> S >> M;
    int e=1,s=1,m=1,rs=1;
    while(true){
        if(e==E && s == S && m == M){
            cout << rs << "\n";
            break;
        }
        e = e >= 15 ? 1 : e+1;
        s = s >= 28 ? 1 : s+1;
        m = m >= 19 ? 1 : m+1;
        rs++;
    }
    return 0;
}