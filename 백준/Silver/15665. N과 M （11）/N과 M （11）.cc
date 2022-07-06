#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void go(vector<pair<int, int> > &pre_num, int n, int m, 
vector<int> &rs, int cnt, int idx){
    if(cnt == m){
        for(auto r : rs)
            cout << r << " ";
        cout << "\n";
        return;
    }
    for(int i=0;i<pre_num.size();i++){
        // if(pre_num[i].second > 0){
        //     pre_num[i].second--;
            rs.push_back(pre_num[i].first);
            go(pre_num, n, m, rs, cnt+1, i);
            // pre_num[i].second++;
            rs.pop_back();
        // }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<pair<int,int> > pre_num;  
    vector<int> rs;
    for(auto &num : numbers)
        cin >> num ;
    sort(numbers.begin(),numbers.end());
    int p=0;
    pre_num.push_back(make_pair(numbers[0],1));
    for(int i=1;i<numbers.size();i++){
        if(numbers[i] == pre_num[p].first){
            pre_num[p].second++;   
        }
        else{
            pre_num.push_back(make_pair(numbers[i], 1));
            p++;
        }
    }
    go(pre_num, n, m, rs, 0, 0);

    return 0;
}