#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

#define MAX 4000000
using namespace std;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    int N, num=2, rp=0,lp=0, sum=2, cnt=0;
    cin >> N;
    vector<bool> chk(N+1, false);
    vector<int> numbers;
    for(int i=2;i<=N;i++){
        if(chk[i] == false){
            numbers.push_back(i);
            for(int j=i*2;j<=N;j+=i) chk[j] = true;
        }
    }
    sum = N < 2 ? 0 : 2;
    while(lp <= rp && rp < numbers.size()){
        if(sum < N){
            rp++;
            sum += numbers[rp];
        }
        else{
            if(sum == N)
                cnt++;
            sum -= numbers[lp];
            lp++;
        }
    }
    cout << cnt << "\n";

    return 0;
}