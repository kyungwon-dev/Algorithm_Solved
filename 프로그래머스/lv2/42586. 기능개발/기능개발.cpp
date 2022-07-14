#include <string>
#include <vector>
#include <iostream>

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
    
    
    
//     if(progresses.size() != deploy)
//         answer[answer.size()-1] = answer[answer.size()-1] + (progresses.size()-deploy);
    
    
//     int time = 0;
//     int deploy = 0;
//     for(int i=0;i<progresses.size();i++){
//         int interval = 100 - progresses[i];
//         if( (interval % speeds[i]) == 0)
//             interval = interval / speeds[i];
//         else
//             interval = (interval / speeds[i]) + 1;
//         time = time + interval;
//         //cout << interval <<  " " << time << "\n";
//         deploy = 0;
//         bool isDeploy = true;
//         for(int j=0;j<progresses.size();j++){
//              if( ((time * speeds[j] + progresses[j]) >= 100) && isDeploy)
//                  deploy++;
//              else{
//                  break;
//              }
                 
//         }
//         answer.push_back(deploy);
//         i=-1;
//         progresses.erase(progresses.begin(),progresses.begin()+deploy);
//         speeds.erase(speeds.begin(),speeds.begin()+deploy);
//     }
    return answer;
}