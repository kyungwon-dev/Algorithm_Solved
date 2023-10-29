#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer(num_list.size()%n == 0 ? num_list.size()/n : num_list.size()/n+1);
    for(int i=0;i<num_list.size();i+=n){
        answer[i/n] = num_list[i];
    }
    return answer;
}