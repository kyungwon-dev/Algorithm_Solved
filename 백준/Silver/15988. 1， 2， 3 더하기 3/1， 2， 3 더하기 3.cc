#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

vector<long long > d(MAX);

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int T;
    cin >> T;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4;i<MAX;i++){
        d[i] = (d[i-1] + d[i-2] + d[i-3]) % 1000000009;
    }    
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        cout << d[n] << "\n";
    }


    return 0;
}
