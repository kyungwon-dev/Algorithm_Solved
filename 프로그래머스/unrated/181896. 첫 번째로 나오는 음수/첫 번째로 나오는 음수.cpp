#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for(auto num : num_list){
        if(num <0)
            return answer;
        answer++;
    }
    return -1;
}