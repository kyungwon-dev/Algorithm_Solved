#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    //int answer = 1234567890;
    for(int i=0;i<a.size();i++)
    {
        a[i] = a[i] * b[i];
    }
    
    return accumulate(a.begin(),a.end(),0);
}