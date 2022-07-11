#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;
int solution(vector<int> d, int budget) {
    int answer = d.size();
    int sum = accumulate(d.begin(),d.end(),0);
    if(sum <= budget)
        return answer;
    sort(d.begin(),d.end(),greater<>());
    budget = sum - budget;
    for(int i=0;i<d.size();i++)
    {
        budget = budget - d[i];
        if(budget<=0)
            return answer - (i+1);
    }
    return 0;
}