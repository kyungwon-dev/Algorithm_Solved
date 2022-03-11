#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, rs=-1;
    int block[19][4][2] = {
        {{0,0}, {0,1}, {0,2}, {0,3}}, // -
        {{0,0}, {1,0}, {2,0}, {3,0}}, // |
        
        {{0,0}, {0,1}, {1,0}, {1,1}}, // ㅁ
        
        {{0,0}, {0,1}, {0,2}, {-1,1}}, // ㅗ
        {{0,0}, {1,0}, {2,0}, {1,-1}}, // ㅓ
        {{0,0}, {1,0}, {2,0}, {1,1}}, // ㅏ
        {{0,0}, {0,1}, {0,2}, {1,1}}, // ㅜ
        
        {{0,0}, {1,0}, {1,1}, {2,1}}, // h
        {{0,0}, {1,0}, {1,-1}, {2,-1}}, 
        {{0,0}, {0,-1}, {1,-1}, {1,-2}}, 
        {{0,0}, {0,1}, {1,1}, {1,2}}, 
        
        {{0,0}, {1,0}, {2,0}, {2,1}}, // L
        {{0,0}, {1,0}, {2,0}, {2,-1}}, // L
        {{0,0}, {0,1}, {1,0}, {2,0}}, // L
        {{0,0}, {0,-1}, {1,0}, {2,0}}, // L
        {{0,0}, {1,0}, {1,1}, {1,2}}, // L
        {{0,0}, {1,0}, {1,-1}, {1,-2}}, // L
        {{0,0}, {0,1}, {0,2}, {1,0}}, // L
        {{0,0}, {0,1}, {0,2}, {1,2}} // L
    };

    cin >> n >> m;
    vector<vector<int> > map(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for(int k=0;k<19;k++){
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                int subsum = 0;
                for(int l=0;l<4;l++){
                    int dy = block[k][l][0];
                    int dx = block[k][l][1];
                    if(i+dy >= 0 && i + dy < n && j + dx >= 0 && j + dx< m )  
                        subsum += map[i+dy][j+dx];
                    else{
                        subsum = 0;
                        break;
                    }
                }
                if(subsum != 0)
                    rs = max(subsum, rs); 
            }
        }
    }
    cout << rs << "\n";
    return 0;
}