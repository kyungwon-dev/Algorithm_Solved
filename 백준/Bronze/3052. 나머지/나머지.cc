#include <iostream>

using namespace std;

int main(){
    int numbers[42] = {0};
    for(int i=0;i<10;i++){
        int n;
        cin >> n;
        numbers[n%42]++;
    }
    int total = 0;
    for(int i=0;i<42;i++){
        if(numbers[i] !=0)
            total++;
    }
    cout << total << "\n";
    return 0;
}