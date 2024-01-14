#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    bool isChoose[100001] = {false,};
    vector<int> answer;
    for(int num : arr){
        if(!isChoose[num]){
            isChoose[num] = true;
            answer.push_back(num);
            k--;
        }
        if(k==0) break;
    }
    if(k!= 0){
        for(int i=0;i<k;i++)
            answer.push_back(-1);
    }
    return answer;
}