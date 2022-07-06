#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<vector<int> > map(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int tmp;
            cin >> tmp;
            map[i].push_back(tmp);
        }
    }
    vector<vector<int> > choose(n);
    choose[0].push_back(map[0][0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0)
                choose[i].push_back(map[i][j] + choose[i-1][j]);
            else if(j==i)
                choose[i].push_back(map[i][j] + choose[i-1][j-1]); 
            else
                choose[i].push_back(max(choose[i-1][j], choose[i-1][j-1]) + map[i][j]);
        }
    }
    cout << *max_element(choose[n-1].begin(), choose[n-1].end()) << "\n";


    return 0;
}
