#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n ,answer2 = n;
    vector<int> people(n,1);
    for(int i=0;i<reserve.size();i++)
        people[reserve[i]-1] = 2;
    for(int i=0;i<lost.size();i++)
        people[lost[i]-1] -= 1;
    vector<int> people2(people.begin(),people.end());
    
    for(int i = people.size()-1;i>=1;i--)
    {
        if( (people[i] == 2) && ( people[i-1] == 0) )
        {
            people[i-1] = 1;
            people[i] = 1;
        }
    }
    
    for(int i = 0;i<people.size()-1;i++)
    {
        if( (people[i] == 2) && ( people[i+1] == 0) )
        {
            people[i+1] = 1;
            people[i] = 1;
        }
    }    
    
    for(int i = 0;i<people.size();i++)
    {
        if(people[i] == 0)
            answer--;
    }
    
    for(int i = 0;i<people2.size()-1;i++)
    {
        if( (people2[i] == 2) && ( people2[i+1] == 0) )
        {
            people2[i+1] = 1;
            people2[i] = 1;
        }
    }    
    for(int i = people2.size()-1;i>=1;i--)
    {
        if( (people2[i] == 2) && ( people2[i-1] == 0) )
        {
            people2[i-1] = 1;
            people2[i] = 1;
        }
    }
    
    
    for(int i = 0;i<people2.size();i++)
    {
        if(people2[i] == 0)
            answer2--;
    }
    
    return max(answer,answer2);
}