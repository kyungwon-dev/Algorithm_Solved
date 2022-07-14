#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first)
        return a.first > b.first;
    return a.second > b.second;
}

int solution(vector<int> priorities, int location) {
    int target = priorities[location], max=-1;
    vector<pair<int,int>> cut_list;
    vector<pair<int,int>> sort_list;
    
    for(int i=0;i<priorities.size();i++){
        if(target>priorities[i])
            continue;
        if(max<priorities[i]) max=priorities[i];
        cut_list.push_back({priorities[i],i});
    }
    int order = -1;
    for(int i=max;i>=target;i--){
        vector<pair<int,int>> tmp;
        for(int j=0;j<cut_list.size();j++){
            if(cut_list[j].first==i){
                if(cut_list[j].second<order)
                    tmp.push_back(cut_list[j]);    
                else
                    sort_list.push_back(cut_list[j]);
            }
        }
        sort_list.insert(sort_list.end(),tmp.begin(),tmp.end());
        order = sort_list[sort_list.size()-1].second;    
        
    }
        
    
    for(int i=0;i<sort_list.size();i++){
        if(sort_list[i].second == location)
            return i+1;
    }
        
        
    
    return -1;
}