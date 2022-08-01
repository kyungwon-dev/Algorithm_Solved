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
    map<string, int> lang_book;
    map<int, string> dec_book;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        lang_book[s] = i+1;
        dec_book[i+1] = s;
    }

    for(int i=0;i<m;i++){
        string tmp;
        cin >> tmp;
        if(lang_book.find(tmp) == lang_book.end()){
            cout << dec_book[stoi(tmp)] << "\n";
        }
        else{
            cout << lang_book[tmp] << "\n";
        }
    }

 	return 0;
}