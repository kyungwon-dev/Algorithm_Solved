#include <string>
#include <vector>

using namespace std;

int solution(vector<string> orders) {
    int answer = 0;
    for(auto order : orders){
        if(order.find("americano") != string::npos){
            answer += 4500;
        } else if(order.find("cafelatte") != string::npos){
            answer += 5000;
        } else{
            answer += 4500;
        }
    }
    return answer;
}