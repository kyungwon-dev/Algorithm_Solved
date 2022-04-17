#include <iostream>
#include <vector>
using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}

void calc_constructor(string n, int &rs, string num, int idx){
    if(num.length() == n.length()){
        int tmp = stoi(num);
        //cout << tmp << "\n";
        for(int i=0;i<num.length();i++){
            tmp += (num[i] - '0');
        }
        if(tmp == stoi(n))
            rs = min(rs, stoi(num));
        return;
    }
    //cout << (n[idx] - '0')  << "\n";
    int mx = idx==0 ? (n[idx] - '0') : 9; 
    for(int i=0;i <= mx; i++){
        char ch = '0' + i;
        num.push_back(ch);
        calc_constructor(n, rs, num, idx+1);
        num.pop_back();
    }

}

int main(){
    setup();
    int n;
    int rs = INT32_MAX;
    cin >> n;
    calc_constructor(to_string(n), rs, "", 0);
    if(rs == INT32_MAX)
        cout << 0 << "\n";
    else
        cout << rs << "\n";
    return 0;
}