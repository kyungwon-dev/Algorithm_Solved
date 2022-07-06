#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    switch(N%5){
        case 1:
            if(N/5 < 1) cout << "-1\n";
            else cout << N/5+1 << "\n";
            break;
        case 2:
            if(N/5 < 2) cout << "-1\n";
            else cout << N/5+2 << "\n";
            break;
        case 3:
            cout << N/5+1 << "\n";
            break;
        case 4:
            if(N/5 < 1) cout << "-1\n";
            else cout << N/5+2 << "\n";
            break;
        default:
            cout << N/5 << "\n";break;
    }
    
    return 0;
}