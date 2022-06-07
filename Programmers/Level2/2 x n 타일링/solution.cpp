#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> nums(n+1,1);
    for(int i=2;i<=n;i++){
        nums[i] = (nums[i-1] + nums[i-2]) % 1000000007;
    }
    return nums[n];
}