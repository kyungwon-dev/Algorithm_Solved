#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    
    sort(citations.begin(),citations.end());
    for(int h=0;h<=n;h++){
        int boundary = n; //h편 이상 인용된 논문
        for(int i=0;i<n;i++){
            if(h<=citations[i]){
                boundary = i;
                break;
            }
        }
        boundary = n - boundary;
        if(boundary<h)
            break;
        if(n-boundary <=h){
            answer = h;
        }
    }
    return answer;
}