#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    cout << N * (M/1%10) << "\n";
    cout << N * (M/10%10) << "\n";
    cout << N * (M/100%10) << "\n";
    cout << N * M << "\n";
    return 0;
    
}

     

     