#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M, answer = INT32_MIN;
        cin >> N >> M;
        int mx =  max(M,N) , mn = min(M,N);
        vector<int> a_i(mx, 0);
        for(int i=0;i<N;i++) cin >> a_i[i];
        vector<int> b_i(mx, 0);
        for(int i=0;i<M;i++) cin >> b_i[i];
            
        for(int i=0;i<= ( mx - mn ); i++){
            int sum =0;
            for(int idx=0;idx<mx;idx++) sum += a_i[idx] * b_i[idx];
            answer = max(answer, sum);
			if(mn == N) rotate(a_i.begin(),a_i.begin()+1,a_i.end());
            else rotate(b_i.begin(),b_i.begin()+1,b_i.end());
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}