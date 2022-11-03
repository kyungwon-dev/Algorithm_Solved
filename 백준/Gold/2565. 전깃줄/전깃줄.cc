#include <iostream>
#include <vector>
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
    int n, longest = -1;
    cin >> n;
    vector<int> power(501,0);
    vector<int> d(501,1);
    for(int i=0;i<n;i++){
        int idx;
        cin >> idx;
        cin >> power[idx];
    }
    for(int i=1;i<=500;i++){
        if(power[i]==0) continue;
        for(int j=1;j<=i;j++){
            if(power[j] < power[i] && power[j] != 0)
                d[i] = max(d[j]+1, d[i]);
        }
        if(d[i] > longest)
            longest = d[i];
    }
    cout << n - longest << "\n";

 	return 0;
}