#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;
    vector<int> alp(26,-1);
    for(int i=0;i<str.length();i++){
        if(alp[str[i]-'a'] !=-1)
            continue;
        alp[str[i]-'a'] = i;
    }
    for(auto i : alp)
        cout << i << " ";
    cout << "\n";
    return 0;
}