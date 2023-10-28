#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer(arr.size());
    int i = 0;
    for(int a : arr){
        if(a%2 == 0 && a>= 50)
            answer[i] = a/2;
        else if(a%2 == 1 && a< 50){
            answer[i] = a*2;
        }
        else{
            answer[i] = a;
        }
        i++;
    }
    return answer;
}