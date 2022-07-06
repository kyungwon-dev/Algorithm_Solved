#include <iostream>
#include <vector>
#define MAX 10001

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    vector<int> cards(MAX, 0);
    vector<int> d(MAX, 10000000);
    cin >> n; 
    for(int i=1;i<=n;i++)
        cin >> cards[i];
    d[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            d[i] = min(d[i], d[i-j] + cards[j]);
        }
    }
    cout << d[n] << "\n";

    
    return 0;
}
