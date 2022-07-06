#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int N;
    cin >> N;
    int num[2] = {0};
    for(int i=1;i<=N;i++){
        if(i%2 == 0){
            int tmp = i;
            while(tmp %2 == 0){
               num[0]++;
               tmp/=2;
            }   
        }
        if(i%5 == 0){
            int tmp = i;
            while(tmp%5 == 0){
               num[1]++;
               tmp/=5;
            }   
        }
    }
    cout << min(num[0], num[1]) << "\n";
    return 0;
}