#include <string>
#include <vector>
#include <numeric>
using namespace std;

string solution(int a, int b) {
    int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string week[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    return week[accumulate(months, months + (a-1), b-1)%7];
}