#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(auto &num : numbers)
        cin >> num;
    sort(numbers.begin(),numbers.end());
    if(numbers.size()%2 == 0)
        cout << numbers[0] * numbers[numbers.size()-1] << "\n";
    else
        cout << numbers[numbers.size()/2] * numbers[numbers.size()/2] << "\n"; 
    
    return 0;
}