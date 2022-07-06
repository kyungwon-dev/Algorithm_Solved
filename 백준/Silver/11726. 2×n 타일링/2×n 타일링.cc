#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> D(MAX);

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    D[1] = 1;
    D[2] = 2;
    for(int i=3;i<=n;i++)
        D[i] = (D[i-1] + D[i-2]) % 10007;
    cout << D[n] << "\n";


    return 0;
}
