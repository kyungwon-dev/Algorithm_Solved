#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n<2)
        return false;
    for(long long i=2;i*i<=n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int num;
        cin >> num;
        int interval = INT32_MAX, nm=0;
        for(int i=2;i<=num/2;i++){
            if(isPrime(i) && isPrime(num-i)){
                if(interval > num-i)
                    nm = i;
            }
        }
        cout << nm << " " << num-nm << "\n";
    }
    
    
    
    return 0;
}