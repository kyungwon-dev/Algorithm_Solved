#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int solution(int n, vector<vector<int>> wires) {
    int answer = INT32_MAX;
    
    for(int i=wires.size()-1;i>=0;i--){
        vector<bool> isCheck (n+1);
        queue<int> q;
        q.push(wires[i][0]);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            isCheck[cur] = true;
            for(int j=0;j<wires.size();j++){
                if(j==i)
                    continue;
                if(wires[j][0] == cur){
                    if(isCheck[wires[j][1]])
                        continue;
                    else
                        q.push(wires[j][1]);                    
                }
                if(wires[j][1] == cur){
                    if(isCheck[wires[j][0]])
                        continue;
                    else
                        q.push(wires[j][0]);                    
                }
            }
        }
        int c1 = 0;
        for(int i=1;i<=n;i++){
            if(isCheck[i])
                c1++;
        }
        answer = min(abs(n-c1-c1),answer);
    }

    return answer;
}