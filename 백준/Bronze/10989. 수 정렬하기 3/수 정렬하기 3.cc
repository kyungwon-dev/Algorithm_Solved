#include <iostream>
#include <vector>
using namespace std;
void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
    
int main(){
    init();
    int n;
    cin >> n;
    vector<int> cnt(10001,0);
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        cnt[num]++;
    }
    for(int i=0;i<cnt.size();i++){
        for(int j=0;j<cnt[i];j++)
            cout << i << "\n";
    }


    return 0;
}