#include <iostream>
#include <vector>


using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    vector<int> d(n+1,0);
    for(int i=1;i<n+1;i++){
        d[i] = i;
        for(int j=1;j*j<=i;j++){
            if(d[i] > d[i-j*j] + 1)
                d[i] = d[i-j*j] + 1;
        }
    }
    cout << d[n] << "\n";
    return 0;
}
