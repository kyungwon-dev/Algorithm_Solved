#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    ll N, S , sum=0;
    int lp=0,rp=0,len=INT32_MAX;
    cin >> N >> S;
    vector<ll> numbers(N);
    for(int i=0;i<N;i++) cin >> numbers[i];
    sum = numbers[0];
    while(lp <= rp && rp <N){
        if(sum < S){
            rp++;
            sum += numbers[rp];
        }
        else if(sum >= S){
            len = min(len, rp-lp+1);
            sum -= numbers[lp];
            lp++;
        }
    }
    if(len == INT32_MAX) len=0;
    cout << len << "\n";

    return 0;
}