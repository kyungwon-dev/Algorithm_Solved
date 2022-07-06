#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double N,M;
    cout.setf(ios::fixed);
    cout.precision(9);
    cin >> N >> M;
    cout << N/ M << "\n";
    
    return 0;
}