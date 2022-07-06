#include <iostream>
#include <vector>
using namespace std;
bool isEnd(string num){
    int isOk = 0;
    for(auto n : num){
        if(n == '6')
            isOk++;
        else
            isOk=0;
        if(isOk == 3)
            return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, idx=1, num = 1666;
    cin >> n;
    if(n==1){
        cout << 666 << "\n";
        return 0;
    }
    while(idx < 10001){
        if(isEnd(to_string(num)) == true)
            idx++;
        if(n == idx){
            cout << num << "\n";
            return 0;
        }
        num++;
    }    
    return 0;
}