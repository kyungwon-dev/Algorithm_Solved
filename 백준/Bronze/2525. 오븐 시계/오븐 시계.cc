#include <iostream>

using namespace std;

int main(){
    int n,m, interval;
    cin >> n >> m >> interval;
    n = (n + ((m+interval) / 60 )) % 24;
    m = (m + interval) % 60;
    cout << n << " " << m << "\n";
    return 0;
    
}