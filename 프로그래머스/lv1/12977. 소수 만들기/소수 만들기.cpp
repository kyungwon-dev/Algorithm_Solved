#include <vector>
#include <iostream>
using namespace std;

void cnt_prime(int & answer,vector<int> nums,int selected,int sum, int idx){
    if(selected == 3){
        //cout << sum << "\n";
        for(int i=2;i<sum/2;i++)
        {
            if(sum%i == 0)
                return ;
        }
        
        answer += 1;
        return;
    }
    if(idx >= nums.size())
        return;

    cnt_prime(answer,nums,selected + 1, sum + nums[idx],idx+1);
    cnt_prime(answer,nums,selected , sum ,idx+1);
    
}

int solution(vector<int> nums) {
    int answer = 0;
    cnt_prime(answer, nums,0,0,0);
    
    return answer;
}