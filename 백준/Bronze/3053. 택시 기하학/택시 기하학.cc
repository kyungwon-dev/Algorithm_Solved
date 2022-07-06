#include <iostream>
#include <cmath>
using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}
int main(){
    setup();
    double r;
    cin >> r;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);
    cout << M_PI * r * r << "\n" << 2 * r * r << "\n";
    return 0;
}