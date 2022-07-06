#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const pair<int, int> a, const pair<int, int> b){
    if(a.first != b.first)
        return a.first < b.first;
    return a.second <= b.second;
}

int main(){
    init();
    int n;
    cin >> n;
    vector<pair<int, int> > coordinate(n);
    for(auto &co : coordinate)
        cin >> co.first >> co.second;
    sort(coordinate.begin(),coordinate.end(),cmp);
    for(auto co : coordinate)
        cout << co.first << " " << co.second << "\n";


    return 0;
}