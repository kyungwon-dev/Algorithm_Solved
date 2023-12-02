#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string a_b = to_string(a) + to_string(b);
    string b_a = to_string(b) + to_string(a);
    if(stoi(a_b) > stoi(b_a)) return stoi(a_b);
    return stoi(b_a);
}