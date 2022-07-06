#include <iostream>

using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}
int fib(int n){
    if(n<2)
        return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    setup();
    int T;
    cin >> T;
    cout << fib(T) << "\n";
    return 0;
}