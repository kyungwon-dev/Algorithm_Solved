#include <iostream>

using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}
struct position{
    long long y,x,r;
};
int main(){
    setup();
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        position pos[2];
        for(int i=0;i<2;i++)
            cin >> pos[i].x >> pos[i].y >> pos[i].r;
        long long dist = (pos[0].x - pos[1].x) * (pos[0].x - pos[1].x) + abs(pos[0].y - pos[1].y) * abs(pos[0].y - pos[1].y);
        long long mx = pos[0].r + pos[1].r;
        long long mn = max(pos[0].r, pos[1].r) - min(pos[0].r, pos[1].r);
        mx *=mx; mn *=mn;
        if(dist == 0){
            if(mn == 0)
                cout << -1 << "\n";
            else
                cout << 0 << "\n";
        }
        else{
            if(dist < mx && dist > mn)
                cout << 2 << "\n";
            else if(dist == mn || dist == mx )
                cout << 1 << "\n";
            else
                cout << 0 << "\n";            
        }
    }
    return 0;
}