#include <iostream>
using namespace std;
int main(){
    int a, b,c;
    cin >> a >> b >> c;
    if(b>=c){
        cout << "-1\n";
        return 0;
    }
    b = c-b;
    cout << a/b+1 << "\n";
    return 0;
}