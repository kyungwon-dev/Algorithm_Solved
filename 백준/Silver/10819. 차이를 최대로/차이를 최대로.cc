#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, sum = INT32_MIN;
    cin >>N;
    vector<int> perm(N,0);
    for(int i=0;i<N;i++)
        cin >> perm[i];
    sort(perm.begin(), perm.end());
    do{
        int tmp = 0;
        for(int i=0;i<N-1;i++)
            tmp += abs(perm[i]-perm[i+1]);
        sum = max(sum,tmp);
    }while(next_permutation(perm.begin(),perm.end()));
    cout << sum << "\n";
    
    return 0;
    
}