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
    vector<vector<int>> arr(n+1);
    for(int i=1;i<=n;i++){
        d[i] = 1;
        arr[i].push_back(a[i]);
        for(int j=1;j<i;j++){
            if(a[j] < a[i] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                arr[i].clear();
                arr[i].assign(arr[j].begin(),arr[j].end());
                arr[i].push_back(a[i]);
            }
        }
    }
    int idx = max_element(d.begin(),d.end()) - d.begin();
    cout << *max_element(d.begin(),d.end()) << "\n";
    for(auto ar : arr[idx])
        cout << ar << " ";
    cout << "\n";
    return 0;
}
