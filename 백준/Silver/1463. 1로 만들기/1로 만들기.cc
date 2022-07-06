#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

vector<int> D(MAX);

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int calc(int n){
    if(n<=1) return 0;
    if(D[n] > 0) return D[n];
    D[n] = calc(n-1) + 1;
    if(n%3 == 0)
        D[n] = min(D[n], calc(n/3)+1);
    if(n%2 == 0)
        D[n] = min(D[n], calc(n/2) + 1);
    return D[n];

}

int main(){
    init();
    int n;
    cin >> n;
    cout << calc(n) << "\n";
    return 0;
}
