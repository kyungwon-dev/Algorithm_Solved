#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<vector<int>> map;
int y = -1, x=0, idx=1;

bool calc(int loop, int dy, int dx){
    for(int i=0;i<loop;i++){
        y = y + dy;
        x = x + dx;
        map[y][x] = idx++;
    }
    if(idx > ( map.size() * (map.size()+1) / 2 ))
        return true;
    return false;
}


vector<int> solution(int n) {
    vector<int> answer;
    map.resize(n,vector<int> (n,0));  
    while(true){
        // up
        if(calc(n--,1,0))
            break;

        //right
        if(calc(n--,0,1))
            break;
        //up + left
        if(calc(n--,-1,-1))
            break;
        
    }    
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++){
            if(map[i][j] != 0)
                answer.push_back(map[i][j]);
        }
    }
    
    return answer;
}