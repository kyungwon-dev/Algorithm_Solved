#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int pos[4] = {0,1,2,3};
    vector<int> tmp(4);
    tmp[0] = land[0][0];
    tmp[1] = land[0][1];
    tmp[2] = land[0][2];
    tmp[3] = land[0][3];
    for(int i=1;i<land.size();i++){
        for(int j=0;j<land[0].size();j++){
            int max = -100;
            int max_pos = -1;
            for(int k=0;k<land[i].size();k++){
                if(pos[j]==k)
                    continue;
                if(max==-100){
                    max = land[0][j] + land[i][k];
                    max_pos = k;
                }
                else{
                    if(max <= (land[0][j] + land[i][k])){
                        max = land[0][j] + land[i][k];
                        max_pos = k;
                    }                   
                }
            }
            land[0][j] = max;   
            pos[j] = max_pos;
        }
        // for(int j=0;j<land[0].size();j++){
        //     cout << pos[j] << " " ;
        // }
        // cout << "\n";
        // for(int j=0;j<land[0].size();j++){
        //     cout << land[0][j] << " " ;
        // }
        // cout << "\n";
    }
    int mx = *max_element(land[0].begin(),land[0].end());
    land[0][0] = tmp[0];
    land[0][1] = tmp[1];
    land[0][2] = tmp[2];
    land[0][3] = tmp[3];
    pos[0] = 0;pos[1] = 1;pos[2] = 2;pos[3] = 3;
    for(int i=(land.size()-2);i>=0;i--){
        for(int j=0;j<land[land.size()-1].size();j++){
            int max = -100;
            int max_pos = -1;
            for(int k=0;k<land[i].size();k++){
                if(pos[j]==k)
                    continue;
                if(max==-100){
                    max = land[land.size()-1][j] + land[i][k];
                    max_pos = k;
                }
                else{
                    if(max <= (land[land.size()-1][j] + land[i][k])){
                        max = land[land.size()-1][j] + land[i][k];
                        max_pos = k;
                    }                   
                }
            }
            land[land.size()-1][j] = max;   
            pos[j] = max_pos;
        }
    //     for(int j=0;j<land[0].size();j++){
    //         cout << pos[j] << " " ;
    //     }
    //     cout << "\n";
    //     for(int j=0;j<land[0].size();j++){
    //         cout << land[0][j] << " " ;
    //     }
    //     cout << "\n";
    }
    
    answer = *max_element(land[land.size()-1].begin(),land[land.size()-1].end()); 
    return (answer> mx ? answer : mx);
}

    
//     answer = ; 
//     return answer;