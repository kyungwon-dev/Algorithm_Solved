#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    int mul = 10000;
    map<int, bool> rankMap;
    map<int, int> indexMap;
    for(int i=0;i<rank.size();i++){
        rankMap.insert(make_pair(rank[i], attendance[i]));
        indexMap.insert(make_pair(rank[i], i));
    }
    map<int, bool>::iterator iter;
    
    for (iter = rankMap.begin(); iter != rankMap.end(); iter++) {
        if(iter->second){
            answer = answer + (mul * indexMap[iter->first]);
            mul /= 100;
        }
        if(mul==0) break;
        
    } 
    return answer;
}