#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N=1, M=1;
    while(true){
        cin >> N >> M;
        if(N==0 && M==0)
            break;
        cout << N+M<<"\n";
        
    }    
    return 0;
    
}