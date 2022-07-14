#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int num1, int num2){
    if(num1 % num2==0)
        return num2;
    return gcd(num2, num1%num2);
}

int solution(vector<int> arr) {
    sort(arr.begin(),arr.end());
    if(arr.size()==1)
        return arr[0];
    int answer = gcd(arr[0],arr[1]);
    answer = arr[0] * arr[1] / answer;
    for(int i=2;i<arr.size();i++){
        int tmp = gcd(answer,arr[i]);
        answer = answer * arr[i] / tmp;
        
    }
    
    return answer;
}