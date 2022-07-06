#include <vector>
long long sum(std::vector<int> &a) {
    long long rs =0 ;
    for(int num : a)
        rs += num;
	return rs;
}
