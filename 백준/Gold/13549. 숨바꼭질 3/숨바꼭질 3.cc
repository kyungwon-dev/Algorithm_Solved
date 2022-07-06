#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

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
    vector<int> check(MAX,0);
    deque<int> dq;
    dq.push_front(n);
    check[n] = 1;
    int move[2] = {1,-1};
    while(!dq.empty()){
        int current = dq.front();
        dq.pop_front();
        if(2*current < MAX){
            if(check[2*current] == 0){
                dq.push_front(2*current);
                check[2*current] = check[current];
            }
        }
        if(current-1 >= 0 ){
            if(check[current-1] == 0){
                dq.push_back(current-1);
                check[current-1] = check[current] + 1;
            }
        }
        if(current + 1 < MAX){
            if(check[current+1] == 0){
                dq.push_back(current+1);
                check[current+1] = check[current] + 1;
            }
        }
    }
    cout << check[m]-1 << "\n";
    

    return 0;
}
