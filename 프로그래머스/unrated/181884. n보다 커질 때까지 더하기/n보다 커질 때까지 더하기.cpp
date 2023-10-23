#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> numbers, int n) {
    int sum = 0;
    for(int number : numbers){
        sum += number;
        if(sum > n) return sum;
    }
    return n;
}