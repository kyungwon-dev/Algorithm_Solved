#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int y[3];
    int x[3]; 
    for(int i=0;i<3;i++)
        cin >> y[i] >> x[i];
    if(y[0] == y[1])
        cout << y[2] << " ";
    else if(y[0] == y[2])
        cout << y[1] << " ";
    else
        cout << y[0] << " ";
    if(x[0] == x[1])
        cout << x[2];
    else if(x[0] == x[2])
        cout << x[1];
    else
        cout << x[0];
    cout << "\n";


    return 0;
}