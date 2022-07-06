#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, max_value=INT32_MIN, min_value = INT32_MAX;
    cin >> N;
    vector<int> numbers(N,0);
    for(int i=0;i<N;i++){
        cin >> numbers[i];
        max_value = max(numbers[i], max_value);
        min_value = min(numbers[i], min_value);
    }
    cout << min_value << " " << max_value << "\n";
    return 0;

}