#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}

int main(){
    init();
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(auto &num : numbers) cin >> num;
    sort(numbers.begin(),numbers.end());
    set<int, less<int> > s;
    for(int i=0;i<n-1;i++)
        s.insert(numbers[i+1] - numbers[i]);
    set<int, less<int> >::iterator it;
    int rs = *s.begin();
    for(it=s.begin();it!=s.end();it++){
        rs = gcd(rs,*it);
    }
    set<int, less<int> > answer;
    for(int i=2;i<=rs/2;i++){
        if(rs % i == 0){
            answer.insert(i);
            answer.insert(rs/i);
        }
    }
    answer.insert(rs);
    for(it = answer.begin();it!=answer.end();it++)
        cout << *it << " ";
    cout << "\n";
    
    return 0;
}