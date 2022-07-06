#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(const string a, const string b){
    if(a.length()!=b.length())
        return a.length() < b.length();
    else{
        for(int i=0;i<a.length();i++){
            if(a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return a[a.length()-1] > b[b.length()-1];
}

int main(){
    init();
    int n;
    cin >> n;
    vector<string> str(n);
    for(auto &s : str)
        cin >> s;
    sort(str.begin(),str.end(),cmp);
    str.erase(unique(str.begin(),str.end()),str.end());
    for(auto &s : str)
        cout << s << "\n";

    return 0;
}