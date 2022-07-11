#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << "#" << test_case << "\n";
        int n;
        cin >> n;
        if(n==1){
            cout << "1 \n";
            continue;
        }
        vector<vector<int>> pascal(n, vector<int> (n,1));
		for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j!=0 && j!=i) pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                cout << pascal[i][j] << " ";
            }
        cout << "\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}