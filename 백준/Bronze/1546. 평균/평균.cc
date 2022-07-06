#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    double max_value= -1.0;
    cin >> N;
    vector<double> scores(N);
    for(int i=0;i<N;i++){
        cin >> scores[i];
        max_value = max(max_value, scores[i]);
    }
    double mean = 0;
    for(int i=0;i<N;i++){
        scores[i] = scores[i] / max_value * 100;
    }
    cout.precision(6);
    cout << accumulate(scores.begin(),scores.end(),0.0) / (double) N << "\n";

    return 0;
}