#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(n==m)
        cout << "==\n";
    else if(n> m)
        cout << ">\n";
    else
        cout << "<\n";
    return 0;
}