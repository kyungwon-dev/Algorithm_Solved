#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int answer = 0;
void go(vector<int> numbers, int sts, int subsum, int op, int target)
{
    if(sts == numbers.size())
    {
        if(subsum == target)
            answer +=1;
        return;
    }
    subsum += (numbers[sts] * op );
    go(numbers,sts+1,subsum,op,target);
    go(numbers,sts+1,subsum,op*-1,target);
    
}

int solution(vector<int> numbers, int target) {
    go(numbers,1,numbers[0] *  1, 1,target);
    go(numbers,1,numbers[0] *  1,-1,target);
    go(numbers,1,numbers[0] * -1, 1,target);
    go(numbers,1,numbers[0] * -1,-1,target);
    return answer/2;
}