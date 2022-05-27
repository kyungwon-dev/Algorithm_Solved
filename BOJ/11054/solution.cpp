#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
        cin >> a[i];
    vector<int> asc(n+1);
    vector<int> desc(n+1);
    for(int i=1;i<=n;i++){
        asc[i] = 1;
        for(int j=1;j<i;j++){
            if(a[j] < a[i] && asc[i] < asc[j] + 1)
                asc[i] = asc[j]+1;
        }
    }
    for(int i=n;i>=1;i--){
        desc[i] = 1;
        for(int j=n;j>i;j--){
            if(a[j] < a[i] && desc[i] < desc[j] + 1)
                desc[i] = desc[j] + 1;
        }
    }
    int mx = INT32_MIN;
    for(int i=1;i<=n;i++)
    {
        if(asc[i] + desc[i] - 1 > mx)
            mx = asc[i] + desc[i] - 1;
    }
    cout << mx << "\n";

    return 0;
}
