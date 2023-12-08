#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string binomial) {
    int answer = 0;
    istringstream ss(binomial);
    string tkn = "";
    string nums[3];
    int i=0;
    while( getline(ss,tkn, ' ' )){
        nums[i++] = tkn;
    }
    if(nums[1] == "*"){
        answer = stoi(nums[0]) * stoi(nums[2]);
    }else if(nums[1] == "+"){
        answer = stoi(nums[0]) + stoi(nums[2]);
    }else{
        answer = stoi(nums[0]) - stoi(nums[2]);
    }
    return answer;
}