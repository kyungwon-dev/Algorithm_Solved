#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);

    int stdnt1[40] = {1,2,3,4,5,1,2,3,4,5,
                      1,2,3,4,5,1,2,3,4,5,
                      1,2,3,4,5,1,2,3,4,5,
                      1,2,3,4,5,1,2,3,4,5};
    int stdnt2[40] = {2,1,2,3,2,4,2,5,
                      2,1,2,3,2,4,2,5,
                      2,1,2,3,2,4,2,5,
                      2,1,2,3,2,4,2,5,
                      2,1,2,3,2,4,2,5};
    int stdnt3[40] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5,
                      3, 3, 1, 1, 2, 2, 4, 4, 5, 5,
                      3, 3, 1, 1, 2, 2, 4, 4, 5, 5,
                      3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for(int i=0;i<answers.size();i++)
    {
        if(stdnt1[i%40] == answers[i])
            score[0] +=1;
        if(stdnt2[i%40] == answers[i])
            score[1] +=1;
        if(stdnt3[i%40] == answers[i])
            score[2] +=1;
    }
    int max = *max_element(score.begin(),score.end());
    for(int i=0;i<score.size();i++)
    {
        if(score[i] == max)
            answer.push_back(i+1);
    }
    
    return answer;
}