#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    int n, m;
    cin >> n >> m;
    map<int, pair<int,int>> sets;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        sets[tmp] = make_pair(1,0);
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        if(sets.find(tmp) == sets.end()){
            sets[tmp] = make_pair(0,1);
        }
        else{
            sets[tmp].second = sets[tmp].second + 1; 
        }
    }
    int answer = 0;
    for(auto s : sets){
        if(s.second.second==0 || s.second.first==0) answer++;
    }
    cout << answer << "\n";
 	return 0;
}