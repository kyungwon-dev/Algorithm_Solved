#include <iostream>
#include <vector>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n, m;
    cin >> n >> m;
    // 인접 행렬
    vector<vector<bool> > adj_matrix(n, vector<bool> (n,false));
    // 인접 리스트
    vector<pair<int,int> > adj_list;
    // 간선 리스트
    vector<vector<int> > egde_list(n);
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        adj_matrix[from][to] = adj_matrix[to][from] = true;
        adj_list.push_back({from, to});
        adj_list.push_back({to, from}); 
        egde_list[from].push_back(to);
        egde_list[to].push_back(from);
    }
    m*=2;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            // A -> B
            int A = adj_list[i].first;
            int B = adj_list[i].second;
            // C -> D
            int C = adj_list[j].first;
            int D = adj_list[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            // B -> C
            if(adj_matrix[B][C] == false)
                continue;
            for(int E : egde_list[D]){
                if(E == A || E == B || E == C || E == D)
                    continue;
                cout << 1 << "\n";
                return 0;
            }            
        }
    }
    cout << 0 << "\n";
    return 0;
}
