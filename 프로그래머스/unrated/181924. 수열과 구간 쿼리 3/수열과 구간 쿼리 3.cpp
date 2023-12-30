#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(int i=0;i<queries.size();i++){
        int prev = queries[i][0];
        int next = queries[i][1];
        int tmp = 0;
        tmp = arr[prev];
        arr[prev] = arr[next];
        arr[next] = tmp;
    }
    
    return arr;
}