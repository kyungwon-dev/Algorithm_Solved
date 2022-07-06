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
    vector<int> cards(MAX);
    vector<int> d(MAX);
    cin >> n; 
    for(int i=1;i<=n;i++)
        cin >> cards[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            d[i] = max(d[i], d[i-j] + cards[j]);
        }
    }
    cout << d[n] << "\n";

    
    return 0;
}
