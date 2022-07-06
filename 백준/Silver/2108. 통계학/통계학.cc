#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
    
int main(){
    init();
    int n, mx= INT32_MIN, mn=INT32_MAX;
    ll sum = 0;
    cin >> n;
    vector<int> cnt(8001,0);
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        num += 4000;
        cnt[num]++;
        if(mx < num)
            mx = num;
        if(mn > num)
            mn = num;
        sum += (num-4000);
    }
    cout << (int) round( (double) sum/n) << "\n";
    int tmp=0;
    bool isFind = false;
    int mid = n%2 == 0 ? n/2 : n/2+1;
    vector<int> ff;
    int freq = *max_element(cnt.begin(),cnt.end());
    for(int i=0;i<cnt.size();i++){
        tmp += cnt[i];
        if(tmp >= mid && isFind == false){
            cout << i-4000 << "\n";
            isFind = true;
        }
        if(cnt[i] == freq)
            ff.push_back(i);
    }
    if(ff.size()>2)
        cout << ff[1] - 4000 << "\n";
    else
        cout << ff[ff.size()-1] - 4000 << "\n";
        
    cout << mx - mn << "\n";

    return 0;
}