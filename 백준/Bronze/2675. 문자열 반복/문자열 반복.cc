#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N;
        string str;
        cin >> N >> str;
        for(int i=0;i<str.length();i++){
            for(int j=0;j<N;j++){
                cout << str[i];
            }
        }
        cout << "\n";
    }
    
    
    return 0;
}