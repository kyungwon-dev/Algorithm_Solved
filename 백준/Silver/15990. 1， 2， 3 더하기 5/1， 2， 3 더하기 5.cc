#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int T;
    vector<vector<long long>> sum_case(MAX,vector<long long> (4, 0));
    cin >> T;
    sum_case[1][1] = 1;
    sum_case[1][2] = sum_case[1][3] = 0;

    sum_case[2][1] = sum_case[2][3] = 0;
    sum_case[2][2] = 1;
    
    sum_case[3][1] = sum_case[3][2] = sum_case[3][3] = 1;
    for(int i=4;i<MAX;i++){
        sum_case[i][1] = (sum_case[i-1][2] + sum_case[i-1][3]) % 1000000009;
        sum_case[i][2] = (sum_case[i-2][3] + sum_case[i-2][1]) % 1000000009;
        sum_case[i][3] = (sum_case[i-3][1] + sum_case[i-3][2]) % 1000000009;
    }
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        cout << (sum_case[n][1] + sum_case[n][2] + sum_case[n][3]) % 1000000009 << "\n";
    }
    
    return 0;
}
