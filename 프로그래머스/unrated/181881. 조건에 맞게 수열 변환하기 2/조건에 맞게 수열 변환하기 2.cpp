#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int same = 0;
    while(same != arr.size()){
        same = 0;
        vector<int> prev(arr.size());
        for(int i=0; i<arr.size(); i++){
            prev[i] = arr[i];
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i] >= 50 && arr[i] %2 == 0){
                arr[i] /=2;    
            } else if(arr[i] < 50 && arr[i]%2 == 1){
                arr[i] = arr[i] * 2 + 1;
            }
            if(arr[i] == prev[i])
                same++;
        }
        answer++;
    }
    return answer-1;
}