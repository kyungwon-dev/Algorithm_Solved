#include <iostream>
#include <vector>
using namespace std;

void go(vector<int> &numbers, vector<bool> & isCheck, 
int n, int m, int cnt){
    if(cnt == m){
        for(auto num : numbers)
            cout << num << " ";
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(isCheck[i] == false){
            isCheck[i] = true;
            numbers.push_back(i);
            go(numbers, isCheck, n, m, cnt+1);
            numbers.pop_back();
            isCheck[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> numbers;
    vector<bool> isCheck(n+1);
    go(numbers, isCheck, n, m, 0);
    
    
    return 0;
}