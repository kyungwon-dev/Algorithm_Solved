#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int min_score = 0;
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    lottos.erase(unique(lottos.begin(),lottos.end()),lottos.end());
    if(lottos[0] == 0)
        lottos.erase(lottos.begin());
    for(int i=0;i<lottos.size();i++)
    {
        for(int j=0;j<win_nums.size();j++)
        {
            if(win_nums[j] == lottos[i])
                min_score++;
        }
    }
    int plus_score = 6-lottos.size();
    
    answer.push_back(min_score+ plus_score <= 1 ? 6 : 7 -( min_score+ plus_score));
    answer.push_back(min_score <= 1 ? 6 : (7 - min_score));
    
    return answer;
}