#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i=1;i<64;i++){
        bitset<6> bits(i);
        int num = stoi(bits.to_string()) * 5;
        if(num >= l && num <= r)
            answer.push_back(num);
    }
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}