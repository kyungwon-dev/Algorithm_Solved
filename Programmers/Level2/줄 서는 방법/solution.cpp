#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer(n+1,0);              // 문자열 반환
    vector<long long> factorials(n+1,1);    // factorial 숫자
    vector<bool> use_num(n+1,false);        // 사용한 숫자
    
    for(int i=1;i<n;i++){
        factorials[i] = factorials[i-1] * i;
    }
    int idx=1,mul=1; 
    long long factorial = factorials[n-1];
    use_num[0] = true;
    while(idx<=n){
        if(k<=factorial){
            int select = 1, i=0;
            while(true){
                i++;
                if(use_num[i])
                    continue;
                if(select == mul) break;
                select++;
            }
            
            k = k - (factorial - factorials[n-idx]);
            answer[idx++] = i;
            mul=1;
            use_num[i] = true;
            factorial = factorials[n-idx];
        }
        else{
            mul++;
            factorial = (mul * factorials[n-idx]);
        }
    }
    answer.erase(answer.begin());
    
    return answer;
}