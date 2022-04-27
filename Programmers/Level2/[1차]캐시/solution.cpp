#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void LRU(vector<string> &caches, int cacheSize, string city, int idx){
    
    if(caches.size() == cacheSize){
        if(idx == -1)
            caches.erase(caches.end()-1, caches.end());
        else
            caches.erase(caches.begin()+idx, caches.begin()+idx+1);
        caches.insert(caches.begin(), city);    
    }
    else
        caches.insert(caches.begin(), city);    

}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0){
        return cities.size() * 5;
    }
    vector<string> caches;
    for(int i=0;i<cities.size();i++){
        transform(cities[i].begin(),cities[i].end(),cities[i].begin(), ::tolower);
        bool isFind = false;
        int idx=-1;
        for(int j=0;j<caches.size();j++){
           if(caches[j] == cities[i]){
               isFind = true;
               idx = j;
               break;
           }
        }
        LRU(caches, cacheSize, cities[i], idx);
        if(isFind == false)
            answer+=5;
        else
            answer++;

    }
    return answer;
}