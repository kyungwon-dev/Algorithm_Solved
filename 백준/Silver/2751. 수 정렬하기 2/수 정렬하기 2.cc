#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> prev(n,0);
    for(auto &p : prev)
        cin >> p;
    sort(prev.begin(),prev.end());
    for(auto p :prev)
        cout << p << "\n";
    
    return 0;
}