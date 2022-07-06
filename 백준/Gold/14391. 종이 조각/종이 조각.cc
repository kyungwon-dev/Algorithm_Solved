#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> vmap;
int n, m, mx=INT32_MIN;
int diry[2] = {0,1};
int dirx[2] = {1,0};
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int check(){
    int answer = 0;
    vector<vector<bool>> chk(n, vector<bool> (m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(chk[i][j] == false){
                string str = "";
                int size = vmap[i][j] == 0 ? m : n;
                int sts = vmap[i][j] == 0 ? j : i; 
                int dy = i , dx = j;
                for(int k=sts;k<size;k++){    
                    if(vmap[i][j] != vmap[dy][dx])
                        break;
                    str.push_back('0' + map[dy][dx]);
                    chk[dy][dx] = true;
                    dy += diry[vmap[i][j]];
                    dx += dirx[vmap[i][j]];
                }
                answer += stoi(str);
            }
        }
    }
    return answer;
}


void calc(int idx){
    if(idx == (n*m)){
        mx = max(check(), mx);
        return;
    }
    int y = idx / m;
    int x = idx % m;
    for(int i=0;i<2;i++){
        vmap[y][x] = i;
        calc(idx+1);
    }   
}

int main(){
    init();
    cin >> n >> m;
    map.resize(n, vector<int> (m,0));
    vmap.resize(n, vector<int> (m,-1)); 

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            if(c=='\n') cin>>c;
            map[i][j] = (c-'0');
        }
    }
    calc(0);
    cout << mx << "\n";


    return 0;
}