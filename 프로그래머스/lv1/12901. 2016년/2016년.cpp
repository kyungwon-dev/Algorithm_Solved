#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

string solution(int a, int b) {
    int months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string week[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    // int day = ;
    // cout << day << "\n";
    // day += (b-1);
    return week[accumulate(months, months + (a-1), b-1)%7];
}