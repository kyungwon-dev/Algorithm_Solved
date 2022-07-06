#include <iostream>
#include <vector>
using namespace std;

void go(vector<int> &numbers,
int n, int m, int cnt){
    if(cnt == m){
        for(auto num : numbers)
            cout << num << " ";
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        numbers.push_back(i);
        go(numbers, n, m, cnt+1);
        numbers.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> numbers;
    go(numbers, n, m, 0);
    
    
    return 0;
}