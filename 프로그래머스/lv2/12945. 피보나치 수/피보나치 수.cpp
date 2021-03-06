#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> fibonacci(n+1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i=2;i<n+1;i++){
        fibonacci[i] = (fibonacci[i-2] + fibonacci[i-1]) % 1234567;
    }
    
    return fibonacci[n];
}