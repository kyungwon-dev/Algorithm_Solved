#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void printmap(vector<vector<int> > &map){
    cout << "==========\n";
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

struct prior{
    int y;
    int x;
    int t;
    prior(int a, int b, int c){
        y=a;
        x=b;
        t=c;
    }
    bool operator<(const prior &p)const{
        if(t!=p.t) return t>p.t;
        if(y!=p.y) return y>p.y;
        return x > p.x;
    }
};

int main(){
    init();
    int tot_time = 0, rabbit = 0;
    int simba = 2, eat=0;
    int N;
    pair<int, int> start;
    cin >> N;
    vector<vector<int> > map(N, vector<int> (N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                start.first = i;
                start.second = j;
            }
            if(map[i][j] != 9 && map[i][j] !=0)
                rabbit++;
        }
    }
    int dy[4] = {-1,0,0,1};
    int dx[4] = {0,-1,1,0};
    while(rabbit!=0){
        vector<vector<bool> > isCheck(N, vector<bool> (N,false)); 
        queue<pair<int, int> > q;
        q.push(start);
        isCheck[start.first][start.second] = true;
        int time = 0, not_eat =0;
        bool move = false;
        priority_queue<prior> pq;
        while(!q.empty()){
            time++;
            int loop = q.size();
            for(int k=0;k<loop;k++){
                int sy = q.front().first;
                int sx = q.front().second;
                for(int i=0;i<4;i++){
                    int yy = sy + dy[i];
                    int xx = sx + dx[i];
                    if(yy >= N || yy < 0 || xx < 0 || xx >= N)
                        continue;
                    if(isCheck[yy][xx])
                        continue;
                    if(map[yy][xx] < simba && map[yy][xx] != 0){
                        pq.push(prior(yy,xx,time));
                        isCheck[yy][xx] = true;
                        // map[start.first][start.second] = 0;
                        // map[yy][xx] = 9;
                        // rabbit--;
                        // eat++;
                        // start.first = yy;
                        // start.second = xx;
                        // move = true;
                        // break;
                    }
                    else if(map[yy][xx] > simba){
                        not_eat++;
                        isCheck[yy][xx] = true;
                        continue;
                    }

                    else{
                        q.push(make_pair(yy,xx));
                        isCheck[yy][xx] =true;
                    }
                }
                q.pop();
                if(move)
                    break;
            }
            if(move)
                break;
            if(not_eat == rabbit){
                cout << tot_time<< "\n";
                return 0;
            }
        }
        if(pq.empty()){
            cout << tot_time << "\n";
            return 0;
        } 
        rabbit--;eat++;
        map[pq.top().y][pq.top().x] = 9;
        map[start.first][start.second] = 0;
        start.first = pq.top().y;
        start.second = pq.top().x;
        tot_time += pq.top().t;
        //printmap(map);
        if(eat == simba){
            simba++;
            eat=0;
        }
    }
    cout << tot_time << "\n";


    return 0;
}