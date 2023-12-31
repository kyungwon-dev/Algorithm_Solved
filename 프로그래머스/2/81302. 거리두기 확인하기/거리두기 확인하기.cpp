#include <string>
#include <vector>

using namespace std;

int diry[] = {0,0,-1,0,-2,-1,-1};
int dirx[] = {-1,1,0,2,0,-1,1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(places.size(),1);
    for(int place=0;place<places.size();place++){
        for(int i=0;i<places[place].size();i++){
            for(int j=0;j<places[place][i].size();j++){
                if(places[place][i][j] == 'P'){
                    int y =i,x=j;
                    for(int k=1;k<7;k++){
                        int dy = y+diry[k], dx = x + dirx[k];
                        if(dy < 0 || dy >= places[place].size() || dx <0 || dx >= places[place][i].size())
                            continue;
                        if(k<=2){
                            if(places[place][dy][dx] == 'P'){
                                i=100;
                                j=100;
                                answer[place] = 0;
                                break;
                            }    
                        }
                        else if(k<=4){
                            if(places[place][dy][dx] == 'P' && places[place][dy + (-1 * diry[k-2])][dx + (-1 * dirx[k-2])] == 'O'){
                                i=100;
                                j=100;
                                answer[place] = 0;
                                break;
                            }
                        }
                        else{
                            if(places[place][dy][dx] == 'P' && 
                               (places[place][y + diry[k-5]][x + dirx[k-5]] == 'O' || places[place][y + diry[2]][x + dirx[2]] == 'O')){
                                i=100;
                                j=100;
                                answer[place] = 0;
                                break;
                            }
                        }
                            
                    }
                }
                    
            }
        }
        
        
    }
    
    
    return answer;
}