#include <iostream>
using namespace std;
int main(){
    int N, sum =1, i=1;
    cin >> N;
    if(N==1){
        cout << "1/1\n";
        return 0;
    }
    while(true){
        if(sum >= N){
            break;    
        }
        i++;
        sum += i;
    }
    if(i%2 == 0) cout << i - (sum - N) << "/" << (sum - N ) + 1 << "\n";
    else cout <<  (sum - N) + 1 << "/" << i - ( sum - N) << "\n";
    return 0;
}