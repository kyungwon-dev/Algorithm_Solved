#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer(num_list.size()-n+1);
    copy(num_list.begin()+n-1,num_list.end(),answer.begin());
    return answer;
}