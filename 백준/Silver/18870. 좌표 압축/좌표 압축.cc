#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    vector<int> original(n);
    map<int, int> idx_map;
    vector<int> idx_list;
    for(int i=0;i<n;i++){
        cin >> original[i];
        idx_list.push_back(original[i]);
    }
    sort(idx_list.begin(),idx_list.end());
    idx_list.erase(unique(idx_list.begin(),idx_list.end()),idx_list.end());
    for(int i=0;i<idx_list.size();i++){
        idx_map[idx_list[i]] = i;
    }
    for(int i=0;i<n;i++){
        cout << idx_map[original[i]] << " ";
    }
    cout << "\n";
    
    return 0;
}