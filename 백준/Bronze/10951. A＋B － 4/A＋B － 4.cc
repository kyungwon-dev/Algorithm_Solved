#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    while(true){
        int N,M;
        cin >> N;
        if(cin.eof())
            break;
        cin >> M;
        if(cin.eof())
            break;
        
        cout << N+M << "\n";
    }
    
    return 0;
    
}