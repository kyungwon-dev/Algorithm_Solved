#include <iostream>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    int d[301][2] = {0};
    int stairs[301] = {0};
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> stairs[i+1];
    }
    d[1][1] = stairs[1];
    d[2][0] = stairs[2];
    d[2][1] = d[1][1] + stairs[2];
    d[3][0] = d[1][1] + stairs[3];
    d[3][1] = d[2][0] + stairs[3];
    for(int i=4;i<=n;i++){
        d[i][0] = max(d[i-2][0], d[i-2][1]) + stairs[i];
        d[i][1] = d[i-1][0] + stairs[i];
    }
    cout << max(d[n][0], d[n][1]) << "\n";
 	return 0;
}