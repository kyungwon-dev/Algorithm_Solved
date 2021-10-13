#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int sum = 0;
    for(char ch : s){
        ch = tolower(ch);
        if(ch=='p')
            sum--;
        else if(ch=='y')
            sum++;
        else
            continue;
    }
           
 
    return (sum==0? true : false);
}