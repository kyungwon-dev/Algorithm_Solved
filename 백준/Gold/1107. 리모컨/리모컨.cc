#include <iostream>
#include <vector>
#define MAX 1000001    

using namespace std;

vector<bool> btn(10, true);

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isCheck(string str){
    for(int i=0;i<str.length();i++){
        if(btn[str[i]-'0'] == false)
            return false;
    }
    return true;
}

int main(){
    init();
    int n, m;
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        btn[tmp] = false;
    }
    int mn = abs(n-100);
    for(int i=0;i<MAX;i++){
        if(isCheck(to_string(i))){
            if(abs(n-i)+ to_string(i).length() < mn){
                mn = abs(n-i) + to_string(i).length();
            }
        }
    }    
    cout << mn << "\n";
    return 0;
}