#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        vector<int> numbers (N, 0);
        for(int i=0; i<N; i++){
            cin >> numbers[i];
        }
        long long sum = 0;
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                sum += gcd(numbers[i], numbers[j]);
            }
        }
        cout << sum << "\n";
    }
    
    return 0;
}