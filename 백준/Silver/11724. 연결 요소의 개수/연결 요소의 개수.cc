#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list(1001);
vector<bool> check(1001);

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int sts){
    check[sts] = true;

    for(int i=0;i<adj_list[sts].size();i++){
        if(check[adj_list[sts][i]])
            continue;
        DFS(adj_list[sts][i]);
    }
}

int main(){
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(check[i] == false){
            DFS( i);
            answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}
