#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int n, k;
    cin >> n >> k;
    vector<long long> acc_sum(n+1, 0);
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        acc_sum[i] = acc_sum[i-1] + num;
    }    
    long long answer = INT64_MIN;
    for(int i=k;i<=n;i++){
        answer = max(answer , acc_sum[i] - acc_sum[i-k]);
    }
    cout << answer << "\n";
 	return 0;
}