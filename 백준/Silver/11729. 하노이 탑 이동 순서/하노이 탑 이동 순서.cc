#include <iostream>
#include <cmath>
using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}

int cnt = 0;
void hanoi(int n, int sts,int end, int mid){
    if(n==1)
        cout << sts << " " << end << "\n";
    else{
        hanoi(n-1, sts, mid, end);
        cout << sts << " " << end << "\n";
        hanoi(n-1, mid, end, sts);
    }
}

int main(){
    setup();
    int n;
    cin >> n;
    cout << (int) pow(2,n) -1 << "\n";
    hanoi(n,1,3,2);
    return 0;
}