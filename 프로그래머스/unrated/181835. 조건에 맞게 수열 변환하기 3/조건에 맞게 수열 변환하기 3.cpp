#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    if(k%2 == 0){
        for(auto &a : arr){
           a = a + k;
        }        
    }
    else{
        for(auto &a : arr){
           a = a * k;
        }        
    }

    return arr;
}