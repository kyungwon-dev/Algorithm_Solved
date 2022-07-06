#include <iostream>

using namespace std;

int main(){
    int tmp,n,max_value=INT32_MIN;
    for(int i=0;i<9;i++){
        cin >> n;
        max_value = max(n, max_value);
        if(n==max_value)
            tmp = i;
    }
    cout << max_value << "\n" << tmp+1 << "\n";
    return 0;
    
}