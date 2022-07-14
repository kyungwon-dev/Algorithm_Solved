#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(int &a, int &b){
    
    string aTos = to_string(a);
    string bTos = to_string(b);    
    
    int mx = max(aTos.length(),bTos.length());
    
    for(int i=0;i<mx;i++)
    {
        int a_idx = (i >= aTos.length() ? i % aTos.length() : i);
        int b_idx = (i >= bTos.length() ? i % bTos.length() : i);
    //    cout <<i << " : " <<  a << " " << b << "\n";
    //    cout << aTos[a_idx] << " " << bTos[b_idx] << "\n";
        if(aTos[a_idx] != bTos[b_idx])
        {
      //     cout << aTos[a_idx] << " " << bTos[b_idx] << "\n";
           return aTos[a_idx] > bTos[b_idx]; 
        }
                       
    }
    return aTos[aTos.length()-1] > bTos[bTos.length()-1];
}

string solution(vector<int> numbers) {
    
    string answer = "";
    sort(numbers.begin(),numbers.end(),compare);    
    for(int num : numbers)
        answer += to_string(num);
    if(answer[0] == '0')
        return "0";
    return answer;
}