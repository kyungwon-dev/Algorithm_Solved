#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 11
using namespace std;

struct ball{
    int y,x;
};

pair<int,int> hole;
struct ball b[2];
int diry[4] = {-1,0,1,0};
int dirx[4] = {0,1,0,-1};

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
}

vector<vector<int>> board_cases;
int map[MAX][MAX];

void make_case(vector<int> board_case){
    if(board_case.size() == 10){
        board_cases.push_back(board_case);
        return;
    }   
    if(board_case[board_case.size()-1]%2 == 0){
        board_case.push_back(1);
        make_case(board_case);        
        board_case.pop_back();
        board_case.push_back(3);
        make_case(board_case);    
    }
    else{
        board_case.push_back(0);
        make_case(board_case);        
        board_case.pop_back();
        board_case.push_back(2); 
        make_case(board_case);    
    }
}

bool select(int dir){
    int dy = b[0].y;
    int dx = b[0].x;
    while(true){
        dy += diry[dir];
        dx += dirx[dir];
        if( (dy  == b[1].y) && 
            (dx  == b[1].x )){
                return true;
            }
        if(map[dy][dx] == -1)
            break;    
    }
    return false;
}

int simulate(int idx, int trial){
    int answer = 100;
    if(trial == 10){
        return 100;
    }
    else{
        int dir = board_cases[idx][trial];
        int start = 0;
        bool red =false, blue = false;
        if(select(dir))
            start = 1;
        for(int i=0;i<2;i++){
            int dy = b[start].y;
            int dx = b[start].x;
            while(true){
                dy = dy + diry[dir];
                dx = dx + dirx[dir];
                if(dy == hole.first && dx == hole.second){
                    if(start == 0)
                        red = true;
                    else
                       blue = true;
                }
                if(map[dy][dx] == -1 || map[dy][dx] == ((start == 0? 2 : 1)) ){
                    dy -= diry[dir];
                    dx -= dirx[dir];
                    break;
                }
            }
            int tmp = map[dy][dx];
            if(tmp == 3){
                map[b[start].y][b[start].x] = 0;
            }
            else{
                map[dy][dx] = map[b[start].y][b[start].x];
                map[b[start].y][b[start].x] = tmp;
                b[start].y = dy;b[start].x=dx;    
            }
            start = (start + 1) % 2;
        }
        if(blue)
            return 100;
        if(red){
            return trial + 1;
        }
         
        answer = min(answer, simulate(idx,trial+1));
    }
    return answer;
}

int main(){
    init();
    //case 생성
    for(int i=0;i<4;i++){
        vector<int> tmp;
        tmp.push_back(i);
        make_case(tmp);
    }
    board_cases[0][0] = 1;
    board_cases[0][1] = 0;
    board_cases[0][2] = 1;
    board_cases[0][3] = 2;
    board_cases[0][4] = 3;
    board_cases[0][5] = 2;
    board_cases[0][6] = 3; 
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            if(c=='\n')
                cin >> c;
            if(c == '#')
                map[i][j] = -1;
            else if(c == '.')
                continue;
            else if(c == 'B'){
                b[1].y = i;
                b[1].x = j;
                map[i][j] = 2;
            }
            else if(c == 'R'){
                b[0].y = i;
                b[0].x = j;   
                map[i][j] = 1;
            }
            else{
                hole.first = i;
                hole.second = j;
                map[i][j] = 3;
            }
        }
    }
    int answer = 100;
    for(int i=0;i<board_cases.size();i++){
        struct ball tmp[2];
        pair<int,int> h;
        h.first = hole.first;h.second = hole.second;
        tmp[0] = b[0];
        tmp[1] = b[1];
        answer = min(answer, simulate(i,0));
        map[b[0].y][b[0].x] = 0;
        map[b[1].y][b[1].x] = 0; 
        map[hole.first][hole.second] = 0;
        b[0] = tmp[0];
        b[1] = tmp[1];
        hole.first = h.first;hole.second = h.second;
        map[b[0].y][b[0].x] = 1;
        map[b[1].y][b[1].x] = 2;
        map[hole.first][hole.second] = 3;
    }
    cout << (answer == 100? -1 : answer )<< "\n";
    return 0;
}
