#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,r;
    cin >> n >> m;
    r = n-m;
    for(int i=m-1;i>0;i--) m*=i;
    for(int i=n-1;i>0;i--) n*=i;
    for(int i=r-1;i>0;i--) r*=i;
    if(m==0)
        m=1;
    if(r==0)
        r=1;
    cout << n/(m*r) << "\n";
    
    return 0;
}