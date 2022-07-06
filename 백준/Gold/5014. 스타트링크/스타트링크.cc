#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int f, s, g, u, d;
    int trial = 0;
    cin >> f >> s >> g >> u >> d;
    vector<bool> isCheck(f+1,false);
    vector<int> length(f+1,0);
    int dir[2];
    dir[0]=u;dir[1]= (d * -1);
    queue<int> q;
    q.push(s);
    isCheck[s] = true;
    length[s] = 0;
    while(!q.empty()){
        int size = q.size();
        for(int roop=0;roop<size;roop++){
            int current = q.front();
            q.pop();
            if(isCheck[g]){
                cout << length[g] << "\n";
                return 0;
            }
            for(int i=0;i<2;i++){
                int next = current + dir[i];
                if(next<1 || next > f)
                    continue;
                if(isCheck[next])
                    continue;
                q.push(next);
                isCheck[next] = true;
                length[next] = length[current]+1;
            }
        }
    }
    cout << "use the stairs\n";
    return 0;
}