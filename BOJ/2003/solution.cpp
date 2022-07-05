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
    int n;
    ll m ;
    cin >> n >> m;
    vector<ll> numbers(n);
    for(int i=0;i<n;i++) cin >> numbers[i];
    int lp=0,rp=1;
    ll sum=0 , cnt=0;
    while(rp <=n){
        sum = accumulate(numbers.begin()+lp, numbers.begin()+rp,0);
        if(sum <= m){
            rp++;
            if(sum==m) cnt++;
        }
        else lp++;
        if(lp > rp) rp++;
    }
    cout << cnt << "\n";

    return 0;
}