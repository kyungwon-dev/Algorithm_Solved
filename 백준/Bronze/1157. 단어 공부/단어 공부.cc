#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int max_value = -1;
    int idx=0;
    cin >> str;
    vector<int> alp(26,0);
    for(int i=0;i<str.length();i++){
        alp[toupper(str[i])-'A']++;
        if(alp[toupper(str[i]) - 'A'] >= max_value){
            max_value = alp[toupper(str[i]) - 'A'];
            idx = toupper(str[i]) - 'A';
        }
    }
    bool isMost = false;
    for(int num : alp){
        if(num == max_value){
            if(!isMost)
                isMost = true;
            else{
                cout << "?\n";
                return 0;
            }
        }
    }
    cout << char('A' + idx) << "\n";
    
    return 0;
}