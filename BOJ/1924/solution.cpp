#include <iostream>
char WEEKDAY[7][5] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
using namespace std;
int main()
{
    int x,y;
    int tmp=0;
    cin >> x >> y;
    if(x==1)
    {
        cout << WEEKDAY[y%7];
        return 0;
    }for(int i=0;i<x-1;i++)
    {
       tmp = tmp + month[i];
    }
    cout << WEEKDAY[(tmp+y)%7]; 
   
    return 0;
}