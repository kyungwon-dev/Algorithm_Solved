#include <iostream>
#include <vector>
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
    const int MAX = 123456;
    vector<bool> numbers(MAX*2+1,true);
    for(int i=2;i<123457;i++){
        if(numbers[i] == false)
            continue;
        if(isPrime(i) == true){
            numbers[i] = true;
            for(int j=i+i;j<MAX*2+1;j+=i)
                numbers[j] = false;
        }
    }
    while(true){
        int N, cnt=0;
        cin >> N;
        if(N==0)
            break;
        for(int i=N+1;i<=N*2;i++){
            if(numbers[i])
                cnt++;
        }
        cout << cnt << "\n";
        
    }
    return 0;
}