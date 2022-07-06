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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin >> a[i];
    vector<int> d(n+1);
    vector<int> sum(n+1);
    for(int i=1;i<=n;i++){
        d[i] = a[i];
        for(int j=1;j<i;j++){
            if(a[j] < a[i] && d[i] < d[j] + a[i]){
                d[i] = d[j] + a[i];

            }
        }
    }
    cout << *max_element(d.begin(),d.end()) << "\n";

    return 0;
}
