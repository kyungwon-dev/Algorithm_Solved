#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<int> d[9];
    if(N == number)
        return 1;
    d[0].push_back(N);
    d[1].push_back(N);
    unordered_set<int> numbers;
    numbers.insert(N);
    cout << N << "\n";
    for(int i=2;i<9;i++){
        answer = i;
        for(int loop = 1;loop<i;loop++){
            for(int j=0;j<d[loop].size();j++){
                for(int k=0;k<d[i-loop].size();k++){
                    for(int m=0;m<4;m++){
                        int rs = 0;
                        if(m==0)
                            rs = d[loop][j] + d[i-loop][k];
                        else if(m==1)
                            rs = d[loop][j] - d[i-loop][k];
                        else if(m==2)
                            rs = d[loop][j] * d[i-loop][k];
                        else
                            rs = d[loop][j] / d[i-loop][k];
                        if(rs <= 0)
                            continue;
                        int size = numbers.size();
                        numbers.insert(rs);
                        if(size == numbers.size())
                            continue;
                        if(rs == number)
                            return answer;
                        d[i].push_back(rs);
                    }
                }
            }
        }
        string tmp(i,'1');
        int size = numbers.size();
        numbers.insert(N*stoi(tmp));
        if(numbers.size() == size)
            continue;
        d[i].push_back(N*stoi(tmp));
        if(N*stoi(tmp) == number)
            return answer;
    }
    return -1;
}