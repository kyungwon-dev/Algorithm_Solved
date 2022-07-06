#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, count =0;
    cin >> N;
    count = N;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        vector<bool> isCheck(26, false);
        for(int i=0;i<str.size();i++){
            int idx = str[i] - 'a';
            if(isCheck[idx] == false)
                isCheck[idx] = true;
            else{
                if(str[i-1] != str[i]){
                    count--;
                    break;
                }
            }
        }
    }
    cout << count << "\n";


    return 0;
}