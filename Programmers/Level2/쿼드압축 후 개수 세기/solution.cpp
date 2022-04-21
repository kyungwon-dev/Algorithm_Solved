#include <string>
#include <vector>
#include <iostream>
using namespace std;


void divide_square(vector<int> &answer, vector<vector<int>> &arr, int y, int x, int len){
    if(len == 1){
        answer[arr[y][x]]++;
        return;
    }
    else{
        int sts = arr[y][x];
        bool isCompress = true;
        for(int i=y;i<y+len;i++){
            for(int j=x;j<x+len;j++){
                if(arr[i][j] != sts){
                    isCompress = false;break;
                    
                }
            }
            if(isCompress == false)
                break;
        }
        if(isCompress){
            answer[arr[y][x]]++;
        }
        else{
            divide_square(answer, arr, y, x, len/2);
            divide_square(answer, arr, y, x + len/2, len/2);
            divide_square(answer, arr, y + len/2, x, len/2);
            divide_square(answer, arr, y + len/2, x + len/2, len/2);
        }
    }
    
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer.push_back(0);answer.push_back(0);
    int len = arr.size();
    divide_square(answer, arr, 0,0, len);
    
    return answer;
}