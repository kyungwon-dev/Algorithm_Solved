#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // 초기값.
    triangle[1][0] += triangle[0][0];
    triangle[1][1] += triangle[0][0];
    cout << triangle[1][0] << " " << triangle[1][1] << "\n";
    for(int i=1;i<triangle.size()-1;i++)
    {
        triangle[i+1][0] += triangle[i][0];
        triangle[i+1][triangle[i+1].size()-1] += triangle[i][triangle[i].size()-1];
        for(int j=1;j<triangle[i+1].size()-1;j++)
            triangle[i+1][j] += max(triangle[i][j-1],triangle[i][j]);
    }
        
    return *max_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
}