#include <iostream>
#include <vector>
using namespace std;
void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}
int main(){
    setup();
    int n;
    cin >> n;
    vector<pair<int, int> > peoples(n, {0, 0});
    for(int i=0;i<n;i++)
        cin >> peoples[i].first >> peoples[i].second;
    vector<int> rank(n, 1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(peoples[i].first < peoples[j].first && peoples[i].second < peoples[j].second)
                rank[i]++;
        }

    }
    for(auto r : rank)
        cout << r << " ";
    cout << "\n";

    return 0;
}