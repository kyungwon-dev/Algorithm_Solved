#include <iostream>

using namespace std;

int gcd(int n, int m){
    if(n%m == 0)
        return m;
    return gcd(m, n%m);
}



int main(){
    int n, m, rs;
    cin >> n >> m;
    rs = gcd(n, m);
    cout << rs << "\n" << (n/rs) * m << "\n";
    
    return 0;
}