#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int> perm(N,0);
    for(int i=0;i<N;i++)
        perm[i] = i+1;
    do{
        for(int n : perm)
            cout << n << " ";
        cout << "\n";
    }while(next_permutation(perm.begin(),perm.end()));
    
    return 0;
    
}