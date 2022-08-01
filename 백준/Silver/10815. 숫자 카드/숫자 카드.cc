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
    int n, m;
    cin >> n;
    map<int, int> cards;
    for(int i=0;i<n;i++){
        int number;
        cin >> number;
        cards[number] = 1;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int ishave;
        cin >> ishave;
        if(cards.find(ishave) == cards.end()){
            cout << "0 ";
        }
        else cout << "1 ";
    }
    cout << "\n";

 	return 0;
}