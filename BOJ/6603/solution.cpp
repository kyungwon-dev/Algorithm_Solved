#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    while(true){
        cin >> N;
        if(N==0)
            break;
        vector<int> check(N, 0);
        vector<int> numbers(N, 0);
        for(int i=0;i<6;i++) check[i] = 1;
        for(int i=0;i<N;i++) cin >> numbers[i];
        sort(numbers.begin(),numbers.end());
        do{
            for(int i=0; i<N;i++){
                if(check[i] == 1)
                    cout << numbers[i] << " ";
            }
            cout << "\n";
        }while(prev_permutation(check.begin(),check.end()));
        cout << "\n";
    }
    
    
    return 0;
}