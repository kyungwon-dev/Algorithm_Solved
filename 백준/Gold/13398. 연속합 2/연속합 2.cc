#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++)
        cin >> a[i];
    vector<int> dl(n+1,0);
    vector<int> dr(n+1,0);
    dl[1] = a[1];
    for(int i=2;i<=n;i++){
        dl[i] = max(dl[i-1] + a[i], a[i]);
    }
    dr[n] = a[n];
    for(int i=n-1;i>0;i--){
        dr[i] = max(dr[i+1] + a[i], a[i]);
    }
    int mx = *max_element(dl.begin()+1,dl.end());
    for(int i=1;i<=(n-1);i++){
        mx = max(mx, dl[i-1] + dr[i+1]);
    }
    cout << mx << "\n";

    return 0;
}
