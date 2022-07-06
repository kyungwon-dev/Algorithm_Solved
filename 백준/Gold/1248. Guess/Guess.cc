#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> answer;
vector<vector<int>> map;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// check
bool check(int idx){
    int sum = 0;
    for(int i=idx;i>=0;i--){
        sum += answer[i];
        if(map[i][idx] < 0 ){
            if(sum >= 0) 
                return false;
        }
        else if(map[i][idx] > 0 ){
            if(sum <= 0) return false;
        }
        else if(map[i][idx] == 0 ){
            if(sum != 0) return false;
        }
    }
    return true;
}


// loop
bool fill_answer(int idx){
    if(idx == map.size()){
        return true;
    }
    else{
        if(map[idx][idx] == 0){
            answer[idx] = 0;
            return check(idx) && fill_answer(idx+1);
        }
        for(int i=1;i<=10;i++){
            answer[idx] = map[idx][idx] * i;
            if(check(idx) && fill_answer(idx+1))
                return true;
        }
    }        
    return false;
}
int main(){
    init();
    int n; cin >> n;
    map.resize(n ,vector<int> (n, 0));
    answer.resize(n);
    for(int i=0;i<n; i++){
        for(int j=i;j<n;j++){
            char c; cin >> c;
            if(c == '-')
                map[i][j] = -1;
            else if(c=='+')
                map[i][j] = 1;
            else
               map[i][j] = 0; 
        }   
    }
    fill_answer(0);
    for(auto a : answer)
        cout << a << " ";
    cout << "\n";
    return 0;
}