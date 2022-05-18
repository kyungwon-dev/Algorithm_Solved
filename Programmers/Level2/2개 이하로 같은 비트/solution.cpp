#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto number : numbers){
        bitset<63> b(number);
        for(int i= 0;i<64;i++){
            if( (1<<i) > number){
                b = (1<<i) + number;
                b[i-1]=0;
                break;
            }
            else{
                if(b[i] == 0){
                    if(i!=0 && b[i-1] == 1){
                        b[i] = 1;
                        b[i-1] = 0;
                    }
                    else
                        b[i] = 1;       
                    break;
                }
            }
        }
        answer.push_back(b.to_ullong());

    }
    return answer;
}