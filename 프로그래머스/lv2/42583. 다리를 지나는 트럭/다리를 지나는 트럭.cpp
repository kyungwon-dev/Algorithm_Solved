#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<int> onbridge(bridge_length,0);
    while(truck_weights.size()!=0){
        answer++;
        onbridge.erase(onbridge.begin(),onbridge.begin()+1);
        int sum = accumulate(onbridge.begin(),onbridge.end(),0);
        if(sum + truck_weights[0] <= weight){
            onbridge.push_back(truck_weights[0]);
            truck_weights.erase(truck_weights.begin(),truck_weights.begin()+1);
        }
        else{
            onbridge.push_back(0);
        }
    }
    
    for(int i=onbridge.size()-1;i>=0;i--){
        if(onbridge[i]!=0){
            answer += i;
            return answer+1;
        }
            
    }
    
    
//     while(truck_weights.size()!=0){
//         if(accumulate(onbridge.begin(),onbridge.end(),0) != 0)
//             onbridge.pop();        
        
        
//         for(int i=0;i<truck_weights.size();i++){
//             if()
            
            
//         }
        
        
//     }
    return answer;
}