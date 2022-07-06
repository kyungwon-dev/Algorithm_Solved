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
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int answer = x, idx;
        for(idx=0;idx<n;idx++){
            answer = (idx * m) + x;
            int dx = answer % m == 0 ? m : answer % m;
            int dy = answer % n == 0 ? n : answer % n;
            if(dx == x && dy == y){
                break;    
            }
        }
        if(idx==n)
            cout << "-1\n";
        else
            cout << answer << "\n";
    }

    return 0;
}