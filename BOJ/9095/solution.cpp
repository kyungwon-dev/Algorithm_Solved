#include <iostream>
#include <vector>

using namespace std;
int count_case = 0;

void calc(int sum, int n){
    if(sum >n)
        return;
    if(sum == n){
        count_case += 1;
        return;
    }
    calc(sum+1, n);
    calc(sum+2, n);
    calc(sum+3, n);
}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int n;
        cin >> n;
        count_case = 0;
        for(int i=1;i<=3;i++){
            calc(i, n);
        }
        cout << count_case << "\n";
    }

    return 0;
}