#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    //Greedy Approach 
    // int mx = number.length()-k;
    // vector<string> greedy(mx+1,"");
    // for(int i=0;i<number.length();i++){
    //     for(int j=mx;j>0;j--){
    //         string tmp = greedy[j-1] + number[i];
    //         if(tmp > greedy[j])
    //             greedy[j] = tmp;
    //     }       
    // }
    // return greedy[mx];
    int answer_length = number.length()-k;
    answer.push_back(number[0]);
    for(int i=1;i<number.length();i++){
        while( (answer[answer.length()-1] - '0') < (number[i] - '0')){
            answer.pop_back();
            k--;
            if(answer.length()==0){
                break;
            }
            if(k==0){
                answer += number.substr(i);
                return answer;
            }

        }
        answer.push_back(number[i]);
    }
    if(answer.length() != answer_length)
        answer = answer.substr(0,answer_length);
    return answer;
}