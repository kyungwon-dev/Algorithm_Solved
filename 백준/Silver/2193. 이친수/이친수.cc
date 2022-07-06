#include <iostream>
#include <vector>
#define MAX 91

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    vector<long long> d(MAX);
    d[1]= 1;
    for(int i=2;i<MAX;i++){
        d[i] = d[i-1] + d[i-2];
    }
    int n;
    cin >> n;
    cout << d[n] << "\n";

    return 0;
}
