#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string numTobit(int n, int &cnt){
    string bit = "";
    while(n!=0){
        bit =to_string(n%2)  + bit ;
        if(n%2 == 1)
            cnt++;
        n = n/2;
    }
    return bit;
}
int bitTonum(string s){
    int num = 0;
    for(int i=(s.length()-1),binary=1;i>=0;i--,binary*=2){
        num = num + (s[i] - '0') * binary;
    }
    return num;
}


int solution(int n) {
    int answer = 0;
    int cnt = 0;
    string bit =  numTobit(n, cnt);
    bit = "0" + bit;
    int sub_cnt = 0;
    next_permutation(bit.begin(),bit.end());
    do{
        sub_cnt =0;
        for(auto c : bit){
            if(c=='1')
                sub_cnt++;
        }
        if(sub_cnt == cnt){
            return bitTonum(bit);
        }
            
    }while(next_permutation(bit.begin(),bit.end()));
    
    
    return bitTonum(bit);
}