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
    vector<int> d(n+1,0);
    d[1] = a[1];
    for(int i=2;i<=n;i++){
        d[i] = max(d[i-1] + a[i], a[i]);
    }
    cout << *max_element(d.begin()+1,d.end()) << "\n";

    return 0;
}
