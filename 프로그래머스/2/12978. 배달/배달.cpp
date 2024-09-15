#include <vector>

#define MAX 500001

using namespace std;

int solution(int N, vector<vector<int> > roads, int K) {
    int answer = 0;
    int map[50][50];
    for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
            if(j!=k)
                map[j][k] = MAX;
            else
                map[j][k] = 0;
        }
    }
    for(auto road : roads){
        if(map[road[0]-1][road[1]-1] > road[2] || map[road[1]-1][road[0]-1] > road[2]){
            map[road[0]-1][road[1]-1] = road[2];
            map[road[1]-1][road[0]-1] = road[2];            
        }
    }
    // i -> 거쳐가는 노드 / j -> 출발 노드 / k -> 도착 노드
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(map[j][k] > map[j][i] + map[i][k])
                    map[j][k] = map[j][i] + map[i][k];
            }
        }
    }    
    for(int i=0;i<N;i++){
        if(map[0][i] <= K)
            answer++;
    }
        
    return answer;
}