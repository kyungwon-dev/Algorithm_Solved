#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> numbers(3,0);
    while(true){
        cin >> numbers[0] >> numbers[1] >> numbers[2];
        sort(numbers.begin(),numbers.end());
        if(numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0)
            break;
        if(numbers[2]*numbers[2] == ((numbers[0] * numbers[0]) + (numbers[1] * numbers[1])))
            cout << "right\n";
        else
            cout << "wrong\n";
        
    }
    return 0;
}