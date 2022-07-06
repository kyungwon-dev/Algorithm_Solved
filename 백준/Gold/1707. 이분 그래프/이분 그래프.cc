#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> check;
bool isBipartie = true;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DFS(int sts, int flag){
    check[sts] = flag;
    for(int i=0;i<adj_list[sts].size();i++){
        if(check[adj_list[sts][i]] == flag){
            isBipartie = false;
            return;
        }
        if(check[adj_list[sts][i]] == 0)
            DFS(adj_list[sts][i], flag * -1);
    }
}

int main(){
    init();
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int v, e;
        cin >> v >> e;
        adj_list.clear();check.clear();
        adj_list.resize(v+1);
        check.resize(v+1);
        isBipartie = true;
        for(int j=0;j<e;j++){
            int from, to;
            cin >> from >> to;
            adj_list[from].push_back(to);
            adj_list[to].push_back(from);
        }
        for(int i=1;i<=v;i++){
            if(check[i] == 0)
                DFS(i, 1);
        }
        if(isBipartie == false)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
    return 0;
}
