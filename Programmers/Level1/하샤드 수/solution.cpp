#include <string>
#include <vector>

using namespace std;

bool solution(int x) {

    string str = to_string(x);
    int sum = 0;
    for(char c : str)
        sum += c - '0';
    return x % sum == 0 ? true : false;
}