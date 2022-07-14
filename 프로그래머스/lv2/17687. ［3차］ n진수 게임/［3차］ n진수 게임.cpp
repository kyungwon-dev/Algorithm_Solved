#include <string>
#include <vector>
#include <iostream>
using namespace std;

string numTobit(int n, int num){
    string rs = "";
    if(num==0)
        return "0";
    while(num!=0){
        int tmp = num % n;
        char c = '0';
        if(tmp >= 10)
            c = 'A' + (tmp-10);
        else
            c += tmp;
        rs = c + rs;
        num /=n;
    }
    return rs;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int sts = 0, dest = m;
    p--;
    while(answer.length()!=t){
        string tmp = "";
        for(int i=sts;i<dest;i++)
            tmp += numTobit(n,i);

        int idx = p;
        while(idx<tmp.length()){
            answer.push_back(tmp[idx]);
            idx += m;
            if(answer.length()==t)
                break;
        }
        p = idx - tmp.length();
        sts = dest;
        dest = dest + m;
    }
    return answer;
}