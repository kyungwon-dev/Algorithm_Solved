#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    set<string> s;
    string str;
    cin >> str;
    for(int i=1;i<=str.length();i++){
        for(int j=0;j<str.length()-i+1;j++){
            s.insert(str.substr(j,i));
        }
    }
    cout << s.size() << "\n";

 	return 0;
}