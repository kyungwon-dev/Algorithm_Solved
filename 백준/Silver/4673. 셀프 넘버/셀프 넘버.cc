#include <iostream>
#include <vector>
#include <string>
using namespace std;

int make_d(int n){
    string str = to_string(n);
    for(char c : str)
        n += c-'0';
    return n;
}

int main(){
    vector<bool> numbers(10001,false);
    for(int i=1;i<10001; i++){
        if(numbers[i]==true)
            continue;
        int prev=i, next=i;
        while(next<10001){
            prev = next;
            next = make_d(next);
            if(prev==next)
                break;
            numbers[next] = true;
        }
    }
    for(int i=1;i<=10000;i++){
        if(numbers[i] == false)
            cout << i << "\n";
    }
        
    return 0;
}