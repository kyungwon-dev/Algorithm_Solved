#include <iostream>

using namespace std;

int numbering(int num){
    if(num%2==0)
        return num/2;
    return (num+1) / 2;
}

int solution(int n, int a, int b)
{
    int answer = 0;

    while(a!=b){
        a = numbering(a);
        b = numbering(b);
        answer++;
    }
    
    return answer;
}