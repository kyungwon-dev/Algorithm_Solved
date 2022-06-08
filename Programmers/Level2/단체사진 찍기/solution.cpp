#include <string>
#include <vector>
#include <algorithm>

struct condition{
    char stt;
    char dest;
    char constraint;
    int distance;
    condition(char c1, char c2, char c3, int a){
        stt = c1;
        dest = c2;
        constraint = c3;
        distance = a;
    }
};

using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int solution(int n, vector<string> datas) {
    int answer = 0;
   	string friends = "ACFJMNRT";
    vector<struct condition> conditions;      
    for(string data : datas){
        struct condition con((char)min(data[0],data[2]),(char)max(data[0],data[2]),data[3],data[4]-'0'+1);
        conditions.push_back(con);
    }
    
    do{
        bool isCorrect = true;
        for(auto condition : conditions){
            int stt = friends.find(condition.stt);
            int dest = friends.find(condition.dest);
            int diff = abs(stt-dest);
            if(condition.constraint == '='){
                if(diff != condition.distance){
                    isCorrect = false;
                    break;
                }
            }
            else if(condition.constraint == '<'){
                if(diff >= condition.distance){
                    isCorrect = false;
                    break;
                }
            }
            else{
                if(diff <= condition.distance){
                    isCorrect = false;
                    break;
                }
            }
        }
        
        if(isCorrect)
            answer++;
    }while(next_permutation(friends.begin(),friends.end()));
    
    return answer;
}