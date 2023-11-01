#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(num_list.size());
    copy(num_list.begin(), num_list.end(), answer.begin());
    answer.push_back(num_list[num_list.size()-1] > num_list[num_list.size()-2] ? num_list[num_list.size()-1] - num_list[num_list.size()-2] : num_list[num_list.size()-1] * 2);
    return answer;
}