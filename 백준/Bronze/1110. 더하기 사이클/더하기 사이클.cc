#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, prev, next, count=0;
    cin >> N;
    prev = N;
    while(true){
        count++;
        next = ((prev/10) + (prev%10)) % 10;
        prev = (prev%10) * 10;        
        next = prev + next;
        if(next == N)
            break;
        prev = next;
    }
    cout << count << "\n";
    return 0;
    
}