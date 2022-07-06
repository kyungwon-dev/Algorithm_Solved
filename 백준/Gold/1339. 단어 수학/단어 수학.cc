#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> d;

vector<string> nums;
string unq = "";
char alpha[100];

long long string_sum(){
    long long ans = 0;
    for(int i=0;i<unq.length();i++)
        alpha[unq[i]] = d[i];
    for(int i=0;i<nums.size();i++){
        long long tmp = 0;
        for(char c : nums[i]){
            tmp = tmp * 10 + alpha[c];
        }
        ans += tmp;
    }
    return ans;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(char c : str){
            if(unq.find(c) == string::npos)
                unq.push_back(c);
        }
        nums.push_back(str);
    }
    for(int i=0;i<unq.size();i++)
        d.push_back(9-i);
    sort(d.begin(),d.end());
    long long mx = INT32_MIN;
    do{
        long long rs = string_sum();     
        if(rs > mx)
            mx = rs;
    }while(next_permutation(d.begin(),d.end()));
    cout << mx << "\n";


    return 0;
}