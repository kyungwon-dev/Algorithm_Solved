#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if(n>0 && m > 0)
        cout << "1\n";
    else if(n > 0 && m < 0)
        cout << "4\n";
    else if( n <0 && m > 0)
        cout << "2\n";
    else
        cout << "3\n";
    return 0;
    
    
}