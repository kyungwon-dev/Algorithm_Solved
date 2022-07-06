#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int T, S=0;
    cin >> T;
    for(int i=0;i<T;i++){
        string op;
        int num;
        cin >> op;
        if(op == "add"){
            cin >> num;
            S = S | (1<<num);
        }
        else if(op == "remove"){
            cin >> num;
            S = S & (~(1<<num));
        }
        else if(op == "check"){
            cin >> num;
            cout << ( (S & (1<<num)) == 0 ? 0 : 1) << "\n";
        }
        else if(op == "toggle"){
            cin >> num;
            S = S ^ (1<<num);
        }
        else if(op == "all"){
            S = ( (1<<21) - 1);
        }
        else{
            S = 0;
        }
    }

    return 0;
}