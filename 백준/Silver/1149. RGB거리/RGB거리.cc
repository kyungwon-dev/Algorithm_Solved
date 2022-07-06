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
    vector<vector<int> > map(n, vector<int> (3,0));
    for(auto &m : map){
        for(auto &h : m){
            cin >> h;
        }
    }
    vector<vector<int> > colored(n, vector<int>(3,0));
    colored[0][0] = map[0][0];
    colored[0][1] = map[0][1];
    colored[0][2] = map[0][2];

    for(int i=1;i<map.size();i++){
        colored[i][0] = min(map[i][0] + colored[i-1][1], map[i][0] + colored[i-1][2]);
        colored[i][1] = min(map[i][1] + colored[i-1][0], map[i][1] + colored[i-1][2]);
        colored[i][2] = min(map[i][2] + colored[i-1][0], map[i][2] + colored[i-1][1]);
    }
    cout << *min_element(colored[n-1].begin(),colored[n-1].end()) << "\n";
    
    return 0;
}