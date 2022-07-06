#include <iostream>
#include <vector>

using namespace std;
int main(){
    int N, sum=1, i=1;
    cin >> N;
    while(true){
        if(N <= sum) break;
        sum = sum + (6*i);
        i++;
    }
    cout << i << "\n";
    return 0; 
}