#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N,M;
        cin >> N >> M;
        cout << "Case #"<< i+1 << ": " << N+M << "\n";
    }
    return 0;
}