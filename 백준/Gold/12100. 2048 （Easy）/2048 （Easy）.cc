#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 맵, 계산에 사용될 맵
vector<vector<int>> map;
vector<vector<int>> instance_map;

//모든 케이스 계산
vector<vector<int>> cases;

int diry[4] = {-1,0,1,0};
int dirx[4] = {0,1,0,-1};

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
}

void calc_case(vector<int> tmp){
    if(tmp.size() == 5){
        cases.push_back(tmp);
        return;
    }else{
        for(int i=0;i<4;i++){
            tmp.push_back(i);
            calc_case(tmp);
            tmp.pop_back();
        }
    }
}

bool isMove(int y, int x){
    if(y<0 || y >= map.size() || x < 0 || x >= map.size())
        return false;
    return true;
}

void print_map(){
    for(int i=0;i<instance_map.size();i++){
        for(int j=0;j<instance_map.size();j++)
            cout << instance_map[i][j] << " ";
        cout << "\n";
    }

}

int simulate(int cases_idx, int case_idx){
    int answer = -1;
    if(case_idx == 5){
        // print_map();
        for(int i=0;i<instance_map.size();i++)
            answer = max(answer , *max_element(instance_map[i].begin(), instance_map[i].end()));
        return answer;
    }
    else{
        int s = cases[cases_idx][case_idx];
        int size = instance_map.size();
        switch (s)
        {
            case 0:
                // 상
                // 탐색 방향 0,0 -> 0, n-1
                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        if(instance_map[j][i] != 0){
                            int dy = j + diry[s];
                            int dx = i + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[j][i];
                               instance_map[j][i] = 0;
                               j-=2;
                            }
                        }
                    }
                }

                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        int dy = j + diry[s];
                        int dx = i + dirx[s];
                        if(isMove(dy,dx) ==false)
                            continue;
                        if(instance_map[dy][dx] == 0)
                            continue;
                        if(instance_map[dy][dx] == instance_map[j][i]){
                            instance_map[dy][dx] *=2;
                            instance_map[j][i] = 0;

                        }
                    }
                }
                
                // 정렬
                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        if(instance_map[j][i] != 0){
                            int dy = j + diry[s];
                            int dx = i + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[j][i];
                               instance_map[j][i] = 0;
                               j-=2;
                            }
                        }
                    }
                }
                break;
            case 1:
                // 우
                // 0,n-1 -> n-1,n-1
                // 정렬
                for(int i=size-1;i>=0;i--){
                    for(int j=size-1;j>=0;j--){
                        if(instance_map[i][j] != 0){
                            int dy = i + diry[s];
                            int dx = j + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[i][j];
                               instance_map[i][j] = 0;
                               j+=2;
                            }
                        }
                    }
                }

                for(int i=size-1;i>=0;i--){
                    for(int j=size-1;j>=0;j--){
                        int dy = i + diry[s];
                        int dx = j + dirx[s];
                        if(isMove(dy,dx) ==false)
                            continue;
                        if(instance_map[dy][dx] == 0)
                            continue;
                        if(instance_map[dy][dx] == instance_map[i][j]){
                            instance_map[dy][dx] *=2;
                            instance_map[i][j] = 0;
                        }
                    }
                }

                // 정렬
                for(int i=size-1;i>=0;i--){
                    for(int j=size-1;j>=0;j--){
                        if(instance_map[i][j] != 0){
                            int dy = i + diry[s];
                            int dx = j + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[i][j];
                               instance_map[i][j] = 0;
                               j+=2;
                            }
                        }
                    }
                }
                // print_map();
                break;
            case 2:
                // 정렬
                for(int i=0;i<size;i++){
                    for(int j=size-1;j>=0;j--){
                        if(instance_map[j][i] != 0){
                            int dy = j + diry[s];
                            int dx = i + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[j][i];
                               instance_map[j][i] = 0;
                               j+=2;
                            }
                        }
                    }
                }
                // 하
                for(int i=0;i<size;i++){
                    for(int j=size-1;j>=0;j--){
                        int dy = j + diry[s];
                        int dx = i + dirx[s];
                        if(isMove(dy,dx) ==false)
                            continue;
                        if(instance_map[dy][dx] == 0)
                            continue;
                        if(instance_map[dy][dx] == instance_map[j][i]){
                            instance_map[dy][dx] *=2;
                            instance_map[j][i] = 0;
                        }
                    }
                }
                // 정렬
                for(int i=0;i<size;i++){
                    for(int j=size-1;j>=0;j--){
                        if(instance_map[j][i] != 0){
                            int dy = j + diry[s];
                            int dx = i + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[j][i];
                               instance_map[j][i] = 0;
                               j+=2;
                            }
                        }
                    }
                }
                // print_map();
                break;
            default:
                // 좌
                                // 정렬
                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        if(instance_map[i][j] != 0){
                            int dy = i + diry[s];
                            int dx = j + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[i][j];
                               instance_map[i][j] = 0;
                               j-=2;
                            }
                        }
                    }
                }

                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        int dy = i + diry[s];
                        int dx = j + dirx[s];
                        if(dy < 0 || dy >= size || dx < 0 || dx >= size){
                            continue;
                        }
                        if(instance_map[dy][dx] == 0)
                            continue;
                        if(instance_map[dy][dx] == instance_map[i][j]){
                            instance_map[dy][dx] *=2;
                            instance_map[i][j] = 0;
                        }
                    }
                }
                // 정렬
                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        if(instance_map[i][j] != 0){
                            int dy = i + diry[s];
                            int dx = j + dirx[s];
                            if(isMove(dy,dx) ==false)
                                continue;
                            if(instance_map[dy][dx] == 0){
                               instance_map[dy][dx] = instance_map[i][j];
                               instance_map[i][j] = 0;
                               j-=2;
                            }
                        }
                    }
                }
                break;
        }
        answer = max(answer, simulate(cases_idx, case_idx + 1));
    }
    return answer;
}

int main(){
    init();
    int n;
    cin >> n;
    map.resize(n, vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> map[i][j];
    }
    for(int i=0;i<4;i++){
        vector<int> tmp;
        tmp.push_back(i);
        calc_case(tmp);
    }
    int answer = -1;
    for(int i=0;i<cases.size();i++){
        instance_map.assign(map.begin(),map.end()); 
        answer = max(answer, simulate(i,0));   
    }
    cout << answer << "\n";
    return 0;
}
