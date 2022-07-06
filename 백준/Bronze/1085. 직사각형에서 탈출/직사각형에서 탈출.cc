#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int y,x,h,w;
    cin >> x >> y >> w >> h;
    cout << min(min(abs(x-0),abs(x-w)), min(abs(y-0),abs(h-y))) << "\n";    
    
    return 0;
}