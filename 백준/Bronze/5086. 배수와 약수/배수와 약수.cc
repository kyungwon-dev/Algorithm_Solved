#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    while(true){
        int a, b;
        cin >> a >> b;
        if(a==b && a==0)
            break;
        if(b>a && b%a==0 ){
            cout << "factor\n";
            continue;
        }
        if( b<a && a%b == 0 ){
            cout << "multiple\n";
            continue;
        }
        cout << "neither\n";
    }
    
    return 0;
}