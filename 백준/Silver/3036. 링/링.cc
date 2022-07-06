#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(auto &num : numbers)
        cin >> num;
    for(int i=1;i<n;i++){
        int tmp = gcd(numbers[0], numbers[i]);
        cout << numbers[0] / tmp << "/" <<numbers[i] / tmp << "\n";
    }
    
    
    
    return 0;
}