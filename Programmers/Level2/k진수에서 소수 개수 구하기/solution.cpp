#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

bool isPrime(long long n){
    if(n<2)
        return false;
    for(long long i=2;i*i<=n;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string ternary = "";
    while(n!=0){
        char c = n%k + '0';
        ternary = c + ternary;
        n = n/k;
    }
    istringstream ss(ternary);
    string tk;
    while(getline(ss,tk,'0')){
        if(tk.length()==0)
            continue;
        if(isPrime(stol(tk)))
            answer++;
    }
    
    return answer;
}