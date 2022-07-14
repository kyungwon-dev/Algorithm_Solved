#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 200001

using namespace std;

struct info{
    int move;
    int prev;
    info(int a, int b){
        move=a;
        prev=b;
    }
};

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int action[3] = {1,-1,2};

int main()
{
    init();
    int N, K;
    cin >> N >> K;
    vector<info> isMove(MAX, info(-1,-1));
    queue<int> q;
    q.push(N);
    isMove[N].move = 0;
    isMove[N].prev = N;
    while(!q.empty()){
        int prev = q.front();
        q.pop();
        for(int i=0;i<3;i++){
            int next = prev;
            if(next == K){
                cout << isMove[K].move << "\n";
                vector<int> history;
                history.push_back(K);
                while(K!=N){
                    history.push_back(isMove[K].prev);
                    K = isMove[K].prev;
                } 
                reverse(history.begin(),history.end());
                for(auto h : history)
                    cout << h << " ";
                cout << "\n";
                return 0;
            }
            if(i<2) next += action[i];
            else next *= action[i];
            if(next < 0 || next >= MAX) continue;
            if(isMove[next].move != -1) continue;
            isMove[next].move = isMove[prev].move + 1;
            isMove[next].prev = prev;
            q.push(next);

        }
    }


	return 0;
}