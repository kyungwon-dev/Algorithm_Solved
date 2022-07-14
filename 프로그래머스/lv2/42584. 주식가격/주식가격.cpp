#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int min;
    min = *min_element(prices.begin(),prices.end());
    for(int i=0;i<prices.size();i++){
        if(prices[i]==min)
            answer.push_back(prices.size()-i-1);
        else{
            bool isDown = false;
            int count=0;
            for(int j=i+1;j<prices.size();j++){
                if(prices[i] > prices[j]){
                    answer.push_back(j-i);
                    isDown=true;
                    break;
                }
            }
            if(isDown==false)
                answer.push_back(prices.size()-i-1);
        }
    }
    return answer;
}