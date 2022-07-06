#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        map<string, int> clothes;
        for(int i=0;i<n;i++){
            string type, cloth;
            cin >> cloth >> type;
            clothes[type]++;
        }
        long long answer = 1;
        map<string, int>::iterator itr;
        for(itr=clothes.begin();itr != clothes.end();itr++)
            answer *= ( (*itr).second + 1);
        cout << answer-1 << "\n";
    }




    return 0;
}