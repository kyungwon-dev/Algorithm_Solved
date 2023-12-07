#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int a_b = stoi(to_string(a) + to_string(b));
    int mul_a_b = 2*a*b;
    return a_b > mul_a_b? a_b : mul_a_b;
}