#include <iostream>
using namespace std;
int main(){
    int A,B,V;
    cin >> A >> B >> V;
    cout << 1 + ( (V-A) / (A-B) ) + ((V-A) % (A-B) == 0? 0 : 1) << "\n";
    return 0;
}