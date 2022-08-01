#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    int n, m, answer=0;
    cin >> n >> m;
    map<string, int> S;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        S[s] = 1;
    }
    for(int i=0;i<m;i++){
        string tmp;
        cin >> tmp;
        if(S.find(tmp) != S.end())
            answer++;
    }
    cout << answer << "\n";

 	return 0;
}