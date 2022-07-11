#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    for(int i=0;i<absolutes.size();i++)
    {
        if(!signs[i])
            absolutes[i] = -1 * absolutes[i];
    }
    
    int answer = accumulate(absolutes.begin(),absolutes.end(),0);
    
    
    return answer;
}