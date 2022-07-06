#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n, k;
    cin >> n >> k;
    int move[100001] = {0};
    queue<int> q;
    q.push(n);
    move[n] = 1;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        int next[3];
        next[0] = current-1;
        next[1] = current+1;
        next[2] = 2 * current;
        for(int i=0;i<3;i++){
            if(next[i] < 0 || next[i] > 100000)
                continue;
            if(move[next[i]] != 0 )
                continue;
            move[next[i]] = move[current] + 1;
            q.push(next[i]);
        }
    }
    cout << move[k]-1 << "\n";


    return 0;
}
