#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void go(vector<int> &numbers, int n, int m, 
vector<int> &rs, vector<bool> &isCheck,  int cnt){
    if(cnt == m){
        for(auto r : rs)
            cout << r << " ";
        cout << "\n";
        return;
    }
    for(int i=0;i<numbers.size();i++){
        if(isCheck[i] == false){
            isCheck[i] = true;
            rs.push_back(numbers[i]);
            go(numbers, n, m, rs, isCheck, cnt+1);
            isCheck[i] = false;
            rs.pop_back();
        }
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<bool> isCheck(n);
    for(auto &num : numbers)
        cin >> num ;
    sort(numbers.begin(),numbers.end()); 
    vector<int> rs;
    go(numbers, n, m, rs, isCheck, 0);
    
    return 0;
}