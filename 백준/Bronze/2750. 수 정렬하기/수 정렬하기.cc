#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> numbers(n,0);
    for(auto &num : numbers)
        cin >> num;
    for(int i=0;i<n;i++){
        int mn = INT32_MAX;
        int mn_idx = 0;
        for(int j=i+1;j<n;j++){
            if(mn > numbers[j]){
                mn_idx = j;
                mn = numbers[j];
            }
        }
        if(mn < numbers[i])
            swap(numbers[i], numbers[mn_idx]);
    }
    for(auto num : numbers)
        cout << num << "\n";
    
    
    
    return 0;
}