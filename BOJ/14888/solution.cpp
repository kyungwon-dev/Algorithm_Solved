#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
}
int minV=INT32_MAX, maxV = INT32_MIN;

void calc_minmax(vector<int> &numbers, int *op, int idx, int sum){
    if(idx == numbers.size()){
        minV = min(sum,minV);
        maxV = max(sum,maxV);    
    }
    else{
        for(int i=0;i<4;i++){
            if(op[i] !=0){
                op[i]--;
                switch(i){
                    case 0:
                        calc_minmax(numbers,op,idx+1,sum + numbers[idx]);
                        break;
                    case 1:
                        calc_minmax(numbers,op,idx+1,sum - numbers[idx]);
                        break;
                    case 2:
                        calc_minmax(numbers,op,idx+1,sum * numbers[idx]);
                        break;
                    default:
                        calc_minmax(numbers,op,idx+1,sum / numbers[idx]);
                        break;    
                }
                op[i]++;
            }
        }
    }
}

int main(){
    init();
    int n;
    cin >> n;
    vector<int> numbers(n);
    int op[4];
    for(int i=0;i<n;i++)
        cin >> numbers[i];
    for(int i=0;i<4;i++)
        cin >> op[i];
    calc_minmax(numbers, op, 1, numbers[0]);
    cout << maxV << "\n" << minV << "\n";
    return 0;
}