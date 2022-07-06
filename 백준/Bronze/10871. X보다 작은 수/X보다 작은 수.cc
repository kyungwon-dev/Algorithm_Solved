#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(tmp < M)
            cout << tmp << " ";
    }
    
    
    return 0;
}