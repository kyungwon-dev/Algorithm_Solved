#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int baseNum = 0;
    string str_three = "";
    for(baseNum=1;baseNum<=n;baseNum*=3);
    baseNum/=3;
    
    for(int i=baseNum;i>=1;i/=3)
    {
        str_three = str_three + to_string(n / i);
        n = n % i;   
    }
    
    int sts = 1;
    //cout << str_three << "\n";
    for(int i=0;i<str_three.length();i++)
    {
        //cout <<  str_three[i] << " " << "\n";
        answer = answer + ((str_three[i] - '0') * sts);
        sts *=3;
            
    }
    return answer;
}