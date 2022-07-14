#include <string>
#include <vector>

using namespace std;


void hanoi(int n, int sts,int end, int mid,vector<vector<int>> &answer){
    if(n==1){
        vector<int> tmp;
        tmp.push_back(sts);
        tmp.push_back(end);
        answer.push_back(tmp);
    }
    else{
        hanoi(n-1, sts, mid, end, answer);
        vector<int> tmp;
        tmp.push_back(sts);
        tmp.push_back(end);
        answer.push_back(tmp);
        hanoi(n-1, mid, end, sts, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n,1,3,2, answer);
    
    return answer;
}