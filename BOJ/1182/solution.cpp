#include <iostream>
#include <vector>

using namespace std;
int cnt = 0;
void sumS(vector<int> numbers, int S, int sum, int index, int check){
    if(index==numbers.size()){
        if(sum == S && check != 0){
            cnt++;
        }
    }
    else{
        sumS(numbers, S, sum + numbers[index], index+1, check+1);
        sumS(numbers, S, sum, index+1, check);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,S;
    cin >> N >> S;
    vector<int> numbers(N,0);
    for(int i=0;i<N;i++)
        cin >> numbers[i];
    sumS(numbers, S, 0, 0,0);
    cout << cnt << "\n";
    return 0;
}