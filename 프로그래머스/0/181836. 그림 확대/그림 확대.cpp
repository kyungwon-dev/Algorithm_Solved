#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer(picture.size() * k);
    for(int i=0;i<answer.size();i++){
        string tmp= "";
        for(int j=0;j<picture[i/k].length(); j++){
            for(int l=0;l<k;l++)
                tmp += picture[i/k][j];
            
        }
        answer[i] = tmp;
    }
    return answer;
}