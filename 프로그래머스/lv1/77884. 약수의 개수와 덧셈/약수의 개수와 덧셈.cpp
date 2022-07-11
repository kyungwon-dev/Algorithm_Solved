#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> msr;
    
    int sts = left;
    while(sts <= right)
    {
        int msr_sum = 1;
        for(int i=1;i<=(sts/2);i++)
        {
            if(sts%i == 0)
                msr_sum++;
        }
        msr.push_back(msr_sum);
        sts++;
    }
    for(int i=left;i<=right;i++)
    {
        if(msr[i-left] % 2 == 0)
            answer += i;    
        else
            answer -= i;   
    }

    return answer;
}