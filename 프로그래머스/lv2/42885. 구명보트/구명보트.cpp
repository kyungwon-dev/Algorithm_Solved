#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1, p=-1;
    sort(people.begin(),people.end());
    vector<int> boats(people.size(),0);
    for(int i=0;i<people.size();i++){
        boats[i] = people.size() - i;  
        if(people[i] > (limit/2) ){
            if(p==-1)
                p = i;
        }
    }
    int rp = boats.size()-1;
    for(int i=0;i<p;i++){
        if(people[rp] + people[i] <= limit){
            boats[i] = boats[rp];
            people[rp] += people[i];
        }
        else{
            rp--;
            i--;
        }
        if(rp == i)
            break;
    }
    // for(auto a : boats){
    //     cout << a << " ";
    // }
    // cout << "\n";
    
    
    return *max_element(boats.begin(),boats.end());
}