#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int totalOftile = brown + yellow;
    for(int i=3;i<=(totalOftile/2 + 1);i++){
        if(totalOftile % i == 0){
            int width = i;
            int height = totalOftile / i;
            for(int minus=1;minus<=width;minus++){
                if( ((width-minus) * (height-minus)) == yellow){
                    answer.push_back(height);
                    answer.push_back(width);
                    return answer;
                }
            }
        }
    }
    return answer;
}