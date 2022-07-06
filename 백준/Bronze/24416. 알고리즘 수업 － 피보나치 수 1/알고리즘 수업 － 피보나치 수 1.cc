#include <iostream>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
}

int arr[41] = {0};
int trial = 1;

int fib(int n){
    if(n<=2)
        return 1;
    trial++;
    return fib(n-2) + fib(n-1);
}


int main(){
    init();
    int n;
    cin >> n;    
    fib(n);
    cout << trial << " " << n-2 << "\n";

    return 0;
}
