#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool finish= false;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isCorrect(vector<vector<int> > map, int y, int x, int num){
    int stsY = 3 * (y/3);
    int stsX = 3 * (x/3);
    for(int i=0;i<9;i++){
        if(map[i][x] == num || map[y][i] == num || map[stsY + (i/3)][stsX + (i%3)] == num)
            return false;
    }    
    return true;
}

vector<int> insertList(vector<vector<int> > &map, int y, int x){
    vector<int> rs;
    vector<bool> isSelect(10,false);

    int stsY = 3 * (y/3);
    int stsX = 3 * (x/3);
    for(int i=0;i<9;i++){
        isSelect[map[i][x]] = true;
        isSelect[map[y][i]] = true;
        isSelect[map[stsY + (i/3)][stsX + (i%3)]] = true;
    }
    for(int i=1;i<10;i++){
        if(isSelect[i] == false)
            rs.push_back(i);
    }

    return rs;
}

void fill(vector<vector<int> > &map, vector<pair<int, int> > slot, int idx){
    if(idx == slot.size()){
        int sum =0;
        for(auto &mm : map){
            sum = accumulate(mm.begin(),mm.end(),0);
            if(sum !=45)
                return;
        }
        finish = true;
        for(auto &mm : map){
            for(auto &m : mm){
                cout << m << " ";
            }
            cout << "\n";
        }

    }
    else{
        int y = slot[idx].first;
        int x = slot[idx].second;
        auto rs = insertList(map,y,x );
        for(int i=0;i<rs.size();i++){
            if(finish)
                return;
            // if(isCorrect(map,y , x ,rs[i])){
            map[y][x] = rs[i];
            fill(map, slot, idx+1);
            map[y][x] = 0;
            // }
        }
    }
}

int main(){
    init();
    vector<vector<int> > map(9, vector<int> (9,0));
    vector<pair<int, int> > slot;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> map[i][j];
            if( map[i][j] == 0)
                slot.push_back(make_pair(i,j));
        }    
    }
    fill(map,slot,0); 

    return 0;
}