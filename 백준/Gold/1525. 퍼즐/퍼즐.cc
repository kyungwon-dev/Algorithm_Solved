#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    int dy[] = {0,1,0,-1};
    int dx[] = {1,0,-1,0};

    map<string,int> cases;
    string p_case = "123456789";
    do{
        cases[p_case] = 0;
    }while(next_permutation(p_case.begin(),p_case.end()));

    string puzzle = "         ";
    for(int i=0;i<puzzle.size();i++){
        char c;
        cin >> c;
        if(c=='\n') cin >> c;
        if(c == '0') c='9';
        puzzle[i] = c;
    }
    queue<string> q;
    q.push(puzzle);
    bool isMake = false;
    while(!q.empty()){
        string now = q.front();
        if(now == "123456789"){
            isMake = true;
            break;
        } 
        q.pop();
        int f = now.find('9');
        int y = f%3, x = f/3;
        for(int k=0;k<4;k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(xx < 0 || xx >= 3 || yy < 0 || yy >= 3)
                continue;
            string next = now;
            swap(next[x*3+y], next[xx*3+yy]);
            if(cases[next] != 0) continue;
            cases[next] = cases[now] + 1;
            q.push(next);
        }
    }    
    if(isMake)
        cout << cases["123456789"] << "\n";
    else
        cout << -1 << "\n";


	return 0;
}