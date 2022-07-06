#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isHan(int n){
    string str = to_string(n);
    if(str.length()==1)
        return true;
    int interval = str[1]-str[0];
    for(int i=2;i<str.length();i++){
        if(str[i] - str[i-1] != interval)
            return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    int cnt =0;
    for(int i=1;i<=N;i++){
        if(isHan(i))
            cnt++;
    }
    cout << cnt << "\n";
    
        
    return 0;
}