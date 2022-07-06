#include <iostream>
#include <string>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int H, W, N;
        cin >> H >> W >> N;
        string str(2 - to_string( (N-1)/H+1).length(),'0');

        cout << (N-1) % H + 1 << str << (N-1) / H + 1 << "\n";
    }
    cout << "\n"; return 0;

}