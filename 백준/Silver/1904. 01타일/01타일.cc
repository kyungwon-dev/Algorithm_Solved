#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> numbers(N+1,0);
    numbers[1] = 1;
    numbers[2] = 2;
    for(int i=3;i<=N;i++){
        numbers[i] = (numbers[i-1] + numbers[i-2]) % 15746;
    }
    cout << numbers[N] << "\n";     
    return 0;
}