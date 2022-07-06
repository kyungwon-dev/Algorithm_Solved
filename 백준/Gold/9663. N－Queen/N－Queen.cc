#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &map, int queen){
    for(int i=0;i<queen;i++){
        if(map[i] == map[queen] || abs(map[queen] - map[i]) == queen - i)
            return false;
    }
    return true;
}

void nQueen(vector<int> &map, int queen, int &answer ){
    if(queen == map.size()){
        answer++;
        return;
    }
    for(int i=0;i<map.size();i++){
        map[queen] = i;
        if(check(map, queen))
            nQueen(map,queen+1,answer);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, answer=0;
    cin >> n;
    vector<int> map(n, 0); 
    nQueen(map,0,answer);
    cout << answer << "\n";    

    return 0;
}