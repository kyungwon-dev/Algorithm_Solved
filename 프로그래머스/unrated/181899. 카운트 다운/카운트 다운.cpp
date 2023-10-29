#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start, int end_num) {
    vector<int> answer(start-end_num+1);
    int i=0;
    while(start >= end_num){
        answer[i++] = start;
        start--;
    }
    return answer;
}