#include <string>
#include <vector>
#include <iostream>

#define MAX 1000000007
using ll = long long;
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<ll>> map(n+1, vector<ll> (m+1,1));
    for(int i=0;i<puddles.size();i++){
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    int diry[2] = {-1,0};
    int dirx[2] = {0,-1};
    for(int i=0;i<=m;i++)
        map[0][i] = 0;
    for(int i=0;i<=n;i++)
        map[i][0] = 0;
    
        
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1)
                continue;
            if(map[i][j] == -1)
                continue;
            int d[2] = {0};
            for(int k=0;k<2;k++){
                int dy = i + diry[k];
                int dx = j + dirx[k];
                if(dy < 0 || dy >n || dx < 0 || dx > m)
                    continue;
                d[k] = map[dy][dx];
            }
            if(d[0] == -1 && d[1] == -1)
                map[i][j] = -1;
            else if(d[0] == -1 && d[1] != -1)
                map[i][j] = d[1];
            else if(d[0] != -1 && d[1] == -1)
                map[i][j] = d[0];
            else{
                map[i][j] = d[0] + d[1];
            }
            map[i][j] = map[i][j] % MAX;
        }
    }

    return (map[n][m] % MAX);
}