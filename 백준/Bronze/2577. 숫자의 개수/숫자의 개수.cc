#include <iostream>

using namespace std;

int main(){
    long long rs = 1;
    for(int i=0;i<3;i++){
        int n;
        cin >> n;
        rs *= n;
    }
    int numbers[10] = {0};
    while(rs>0){
        numbers[rs%10]++;
        rs /=10;
    }
    for(int i=0;i<10;i++)
        cout << numbers[i] << "\n";
    return 0;
}