#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        int sum=0, accumlate=0;
        for(char c : str){
            if(c=='X'){
                sum = sum + ((accumlate) * (accumlate+1)) / 2;
                accumlate=0;
            }
            else
                accumlate++;
        }
        sum = sum + ((accumlate) * (accumlate+1)) / 2;
        cout << sum << "\n";
    }


    return 0;
}