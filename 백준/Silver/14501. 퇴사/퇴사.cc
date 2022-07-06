#include <iostream>
#include <vector>
#include <string>

using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void drawUpschedule(vector<pair<int, int> > schedule, int &max_benefit, int next, int days, int sum){
    if(next == days){
        max_benefit = max(max_benefit, sum);
        return;
    }
    if(next > days)
        return;
    else{
        drawUpschedule(schedule, max_benefit,next+schedule[next].first,
        days,sum + schedule[next].second );
        drawUpschedule(schedule, max_benefit,next+1, days,sum );
    }
}


int main(){
    init();
    int N, max_benefit=INT32_MIN;
    cin >> N;
    vector<pair<int, int> > schedule(N);
    for(auto &sc : schedule)
        cin >> sc.first >> sc.second;
    drawUpschedule(schedule,max_benefit, 0, N, 0);
    cout << max_benefit << "\n";

    return 0;
}