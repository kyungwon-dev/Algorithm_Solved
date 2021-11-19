#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,search;
    cin >> n >> search;
    vector<vector<int>> map(n,vector<int>(n,0));
    int startY = 0, startX = 0;
    int startNum = n*n+1;

    while(startNum!=1){
        
        //하
        for(;startY<n;startY++){
            if(map[startY][startX]!=0)
                break;
            map[startY][startX] = (--startNum);
        }
        startY--;
        startX++;
        //우
        for(;startX<n;startX++){
            if(map[startY][startX]!=0)
                break;
            map[startY][startX] = (--startNum);
        }
        startY--;
        startX--;
        // 상
        for(;startY>=0;startY--){
            if(map[startY][startX]!=0)
                break;
            map[startY][startX] = (--startNum);
        }
        startY++;
        startX--;
        //좌
        for(;startX>=0;startX--){
            if(map[startY][startX]!=0)
                break;
            map[startY][startX] = (--startNum);
        }
        startY++;
        startX++;
    }


    for(int i=0;i<n;i++){
        if(map[i][0]==search){
            startY=i+1;
            startX=0+1;
        }

        cout << map[i][0];
        for(int j=1;j<n;j++){
            if(map[i][j]==search){
                startY=i+1;
                startX=j+1;
            }
            cout << " " << map[i][j];
        }
        cout << "\n";
    }
    cout << startY << " " << startX << "\n";


    return 0;
}
