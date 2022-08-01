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
    map<string, int> not_hear;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        not_hear[s] = 0;
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        string tmp;
        cin >> tmp;
        if(not_hear.find(tmp) != not_hear.end()){
            not_hear[tmp]++;
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(auto person : not_hear){
        if(person.second > 0)
            cout << person.first << "\n";
    }

 	return 0;
}