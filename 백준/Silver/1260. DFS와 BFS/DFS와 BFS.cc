#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(vector<vector<int>> adj_list, vector<bool> &check, int sts){
    cout << sts << " ";
    check[sts] = true;
    for(int i=0;i<adj_list[sts].size();i++){
        if(check[adj_list[sts][i]])
            continue;
        DFS(adj_list, check, adj_list[sts][i]);
    }
}


int main(){
    init();
    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> adj_list(n+1);
    vector<bool> check(n+1);
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    for(int i=0;i<n+1;i++)
        sort(adj_list[i].begin(),adj_list[i].end());
    DFS(adj_list, check, v);
    cout << "\n";
    check.clear();check.assign(n+1,false);
    queue<int> q;
    q.push(v);check[v]=true;
    while(!q.empty()){
        int next = q.front();
        q.pop();
        cout << next << " ";
        for(int i=0;i<adj_list[next].size();i++){
            if(check[adj_list[next][i]])
                continue;
            q.push(adj_list[next][i]);check[adj_list[next][i]] = true;
        }
    }
    cout << "\n";
    return 0;
}
