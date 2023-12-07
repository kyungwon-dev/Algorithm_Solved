#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    for(int a : arr){
        bool isCheck = true;
        for (int d : delete_list){
            if(a == d){
                isCheck = false;
                break;
            }
        }
        if(isCheck) answer.push_back(a);
    }
    return answer;
}