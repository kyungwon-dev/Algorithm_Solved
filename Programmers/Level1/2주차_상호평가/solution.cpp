#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char calc_score(double mean){
    //cout << mean << "\n";
    if(mean >= 90)
        return 'A';
    else if(mean >= 80)
        return 'B';
    else if(mean >= 70)
        return 'C';
    else if(mean >= 50)
        return 'D';
    return 'F';
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    for(int student = 0;student<scores.size();student++){
        
        int max = INT32_MIN;
        int min = INT32_MAX;
        int divide = scores[student].size();
        int sum=0, isUnique = 0;
        
        for(int number = 0; number < scores[student].size();number++){
            if(scores[number][student] > max)
                max = scores[number][student];
            if(scores[number][student] < min)
                min = scores[number][student];
            if(scores[number][student] == scores[student][student])
                isUnique++;
            sum += scores[number][student];
            
        }
        if(isUnique == 1){
            if(max==scores[student][student]){
                sum -= max;
                divide--;
            }
            if(min==scores[student][student]){
                sum -= min;
                divide--;
            }   
        }
        answer.push_back(calc_score((double)sum / (double)divide));
        
    }
    
    return answer;
}