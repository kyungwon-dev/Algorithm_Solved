#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N, sum=0;
        cin >> N;
        vector<int> numbers(N);
        for(int i=0;i<N;i++){
            cin >> numbers[i];
            sum += numbers[i];
        }
        double mean = sum / (double) N;
        int up_mean = 0;
        for(int num : numbers){
            if((double) num > mean)
                up_mean++;
        }
        mean = up_mean / (double) N;
        mean = round(mean * 100000) / 100000;
        cout.precision(3);
        cout << fixed;
        cout << mean*100 << "%" << "\n";
       
    }


    return 0;
}