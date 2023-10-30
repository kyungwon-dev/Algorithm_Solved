#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(5);
    sort(num_list.begin(), num_list.end());
    copy(num_list.begin(),num_list.begin() + 5, answer.begin());
    return answer;
}