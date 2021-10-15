using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = (long long) price * (long long) count * (long long) (count+1) / 2;
    return money > answer ? 0 : answer - money;
}