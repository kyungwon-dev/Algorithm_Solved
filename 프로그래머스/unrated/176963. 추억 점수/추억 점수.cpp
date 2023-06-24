#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photoAlbum) {
    vector<int> answer;
    map<string, int> missScore;
    for(int i=0;i<name.size();i++){
        missScore[name[i]] = yearning[i];
    }
    for(vector<string> photos : photoAlbum){
        int score = 0;
        for(string photo : photos){
            score += missScore[photo];
        }
        answer.push_back(score);
    }
    return answer;
}