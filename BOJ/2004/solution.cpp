#include <iostream>
#include <vector>

typedef unsigned long long ll;
using namespace std;

pair<ll,ll> calc_zero(ll n){
    pair<ll, ll> rs;
    for(ll i=2;i<=n;i*=2){
        rs.first += (n/i);
    }
    for(ll i=5;i<=n;i*=5){
        rs.second += (n/i);
    }
    return rs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    ll N, M;
    cin >> N >> M;
    pair<ll, ll> n_ = calc_zero(N), r_ = calc_zero(M), n_r = calc_zero(N-M);
    ll five = n_.second - r_.second - n_r.second;
    ll two = n_.first - r_.first - n_r.first; 
    cout << min(five,two) << "\n";

   return 0;
}