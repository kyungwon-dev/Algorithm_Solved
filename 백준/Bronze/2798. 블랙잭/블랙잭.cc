#include <iostream>
#include <vector>
using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}

void calc_jack(vector<int> &cards, int m, int cnt, int idx, int sum, int &rs){
    if(3 == cnt){
        if(sum <= m)
            rs = max(rs, sum);
        return;
    }
    if(idx==cards.size())
        return;
    calc_jack(cards, m, cnt+1, idx+1, sum + cards[idx], rs);
    calc_jack(cards, m, cnt, idx+1, sum, rs);
}

int main(){
    setup();
    int n, m;
    int rs = INT32_MIN;
    cin >> n >> m;
    vector<int> cards(n);    
    for(auto &card : cards)
        cin >> card;
    calc_jack(cards, m, 0, 0, 0, rs);
    cout << rs << "\n";


    return 0;
}