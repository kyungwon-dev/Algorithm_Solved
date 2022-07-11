#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    if(num==1)
        return 0;
    long long ext_num = num;
    
    for(int i=1;i<=500;i++){
        if((ext_num%2)==0)
            ext_num /=2;
        else
            ext_num = ext_num * 3 + 1;
        if(ext_num==1)
            return i;
    }
    return -1;
}