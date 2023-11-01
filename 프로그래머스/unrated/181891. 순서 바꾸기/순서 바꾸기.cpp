#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer(num_list.size());
    int idx= 0;
    for(int i=n;i<num_list.size();i++){
        answer[idx++] = num_list[i];
    }
    for(int i=0;i<n;i++){
        answer[idx++] = num_list[i];
    }

    return answer;
}