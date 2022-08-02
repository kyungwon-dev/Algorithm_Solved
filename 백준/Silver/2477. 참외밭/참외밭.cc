#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    int per, answer = 0;
    cin >> per;
    vector<pair<int,int>> line(6);
    for(int i=0;i<6;i++){
        int dir, num;
        cin >> dir >> num;
        line[i].first = dir;
        line[i].second = num;
    }
    //max 구하기
    int wid=0, hei=0;
    for(int i=0;i<6;i++){
        if(line[i].first <= 2){
            wid = max(line[i].second, wid);
        }
        else
            hei = max(line[i].second, hei);
    }
    answer = wid * hei;
    //작은 사각형 구하기
    for(int i=0;i<6;i++){
        if(line[0].first == line[2].first && line[1].first == line[3].first){
            answer = (answer - (line[1].second * line[2].second) ) * per;
            break;
        }
        rotate(line.begin(),line.begin()+1,line.end());
    }
    cout << answer << "\n";

 	return 0;
}