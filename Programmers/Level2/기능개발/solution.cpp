#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        if( (100 - progresses[i]) % speeds[i] == 0)
            progresses[i] = (100 - progresses[i]) / speeds[i];
        else
            progresses[i] = (100 - progresses[i]) / speeds[i] + 1;
    }
    int deploy = 0;
    for(int i=0;i<progresses.size();i++){
        for(int j=i;j<progresses.size();j++){
            if(progresses[i] >= progresses[j])
                deploy++;
            else
                break;
        }
        
        answer.push_back(deploy);
        progresses.erase(progresses.begin(),progresses.begin()+deploy);
        i=-1;deploy = 0;
    }
    return answer;
}