#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    const int MAX = 15;
    vector<vector<int> > numbers(MAX, vector<int> (MAX,0));
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(i==0)
                numbers[i][j] = j;
            else
                numbers[i][j] = accumulate(numbers[i-1].begin(),numbers[i-1].begin()+j+1,0);
        }
    }
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int a, b;
        cin >> a >> b;
        cout << numbers[a][b] << "\n";
    }
    return 0;

}