#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int> perm(N,0);
    for(int i=0;i<N;i++)
        cin >> perm[i];
    if(next_permutation(perm.begin(),perm.end()) == false)
        cout << "-1\n";
    else{
        for(int n : perm)
            cout << n << " ";
        cout << "\n";
    }
    
    return 0;
    
}