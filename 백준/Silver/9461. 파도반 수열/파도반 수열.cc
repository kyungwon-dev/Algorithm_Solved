#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    vector<long long> squares(101,1);
    squares[4] = 2;
    squares[0] = 0;
    for(int i=5;i<101;i++){
        squares[i] = squares[i-1] + squares[i-5];
    }
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        cout << squares[n] << "\n";
    }

    return 0;
}