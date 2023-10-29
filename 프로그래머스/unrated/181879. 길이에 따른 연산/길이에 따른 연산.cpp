#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 1;
    if(num_list.size() >= 11) return accumulate(num_list.begin(),num_list.end(), 0);
    for(auto num : num_list){
        answer *= num;
    }
    return answer;
}