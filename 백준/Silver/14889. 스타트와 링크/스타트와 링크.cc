#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<vector<int> > &map,vector<bool> &arr){
    int rs = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == false)
            continue;
        for(int j=i;j<arr.size();j++){
            if(arr[j] == false)
                continue;
            rs += map[i][j] + map[j][i];
        }
    }

    return rs;
}

void choice(vector<vector<int> > &map, vector<bool> &select, int &answer, int idx, int len){
    if(len == map.size()/2){
        vector<bool> not_select(select.size(), false);
        for(int i=0;i<map.size();i++){
            if(select[i] == false)
                not_select[i] = true;
        }
        answer = min(answer, abs(calc(map, select) - calc(map,not_select)) );
    }    
    if(idx == map.size())
        return;
    else{
        select[idx] = true;
        choice(map, select, answer,idx+1,len+1);
        select[idx] = false;
        choice(map, select, answer,idx+1,len);
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, start = 0, link = 0, answer = INT32_MAX;
    cin >> n;
    vector<vector<int> > map(n, vector<int> (n, 0)); 
    vector<bool> select(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    choice(map, select, answer, 0, 0 );
    cout << answer << "\n";
    return 0;
}