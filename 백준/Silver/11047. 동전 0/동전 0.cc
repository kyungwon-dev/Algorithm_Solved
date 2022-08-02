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
    int n, k, answer=0;
    cin >> n >> k;
    vector<int> coins(n);
    for(auto &coin : coins) cin >> coin;
    for(int i=n-1;i>=0;i--){
        if(coins[i] <= k){
            answer += k/coins[i];
            k = k - (k/coins[i]*coins[i]);
        }
    }
    cout << answer << "\n";
 	return 0;
}