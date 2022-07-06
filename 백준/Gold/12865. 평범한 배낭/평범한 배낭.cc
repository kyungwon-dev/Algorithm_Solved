#include <iostream>
#include <vector>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
}

int main(){
    init();
    int n, k;
    cin >> n >> k;
    vector<int> bag(k+1);
    for(int i=0;i<n;i++){
        int w, v;
        cin >> w >> v;
        for(int j=k;j>=w;j--){
            bag[j] = max(bag[j], bag[j-w] + v);
        }
    }
    cout << bag[k] << "\n";
    return 0;
}
