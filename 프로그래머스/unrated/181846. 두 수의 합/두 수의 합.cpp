#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string a, string b) {
    string answer = "";
    if(a.size() > b.size()){
        int s = b.size();
        for(int i=0;i<a.size() - s; i++){
            b = "0" + b;
        }
    } else{
        int s = a.size();
        for(int i=0;i<b.size() - s; i++){
            a = "0" + a;
        }
    }
    int carry = 0;
    for(int i=a.size()-1; i>= 0; i--){
        int aa = a[i] - '0';
        int bb = b[i] - '0';
        if(aa + bb + carry >= 10){
            answer = to_string( (aa + bb + carry) % 10) + answer;
            carry = 1;
        } else{
            answer = to_string( (aa + bb + carry) % 10) + answer;
            carry = 0;
        }
        
    }
    if(carry == 1)
        answer = "1" + answer;
    return answer;
}