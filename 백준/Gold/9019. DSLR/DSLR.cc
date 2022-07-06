#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int D(int num){ return (num*2) % 10000; }
int S(int num){ return num==0? 9999 : num-1;}
int R(int num){ return (num%10*1000) + num / 10; }
int L(int num){ return (num%1000 * 10) + num/1000; }

int main(){
    init();
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        vector<bool> isCheck(10000, false);
        vector<string> proc(10000); 
        int n, m;
        cin >> n >> m;
        queue<int> q;
        q.push(n);
        isCheck[n] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int next = q.front();
                q.pop();
                int tmp;
                for(int j=0;j<4;j++){
                    if(j==0){
                        tmp = D(next);
                        if(isCheck[tmp])
                            continue;
                        isCheck[tmp] = true;
                        proc[tmp] = proc[next] + "D";
                        q.push(tmp);
                    }
                    else if(j==1){
                        tmp = S(next);
                        if(isCheck[tmp])
                            continue;
                        isCheck[tmp] = true;
                        proc[tmp] = proc[next] + "S";
                        q.push(tmp);
                    }
                    else if(j==2){
                        tmp = L(next);
                        if(isCheck[tmp])
                            continue;
                        isCheck[tmp] = true;
                        proc[tmp] = proc[next] + "L";
                        q.push(tmp);
                    }
                    else{
                        tmp = R(next);
                        if(isCheck[tmp])
                            continue;
                        isCheck[tmp] = true;
                        proc[tmp] = proc[next] + "R";
                        q.push(tmp);
                    }
                }
            }
            if(isCheck[m]){
                cout << proc[m] << "\n";
                break;
            }
        }
    }

    return 0;
}
