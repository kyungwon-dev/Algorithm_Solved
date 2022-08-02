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
    int n, m;
    cin >> n >> m;
    vector<long long> acc_sum(n+1, 0);
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        acc_sum[i] = acc_sum[i-1] + num;
    }    
    for(int i=0;i<m;i++){
        int st, dt;
        cin >> st >> dt;
        cout << acc_sum[dt] - acc_sum[st-1] << "\n";
    }

 	return 0;
}