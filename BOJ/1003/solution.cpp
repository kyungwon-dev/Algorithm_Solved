#include <iostream>
#include <vector>

using namespace std;


void fib(int input, vector<pair<int,int>> &storeFib)
{
	storeFib.push_back(make_pair(1, 0));
	storeFib.push_back(make_pair(0, 1));
	for (int i = 2; i <= input; i++)
	{
		pair<int, int> tmp;
		tmp.first = storeFib[i - 2].first + storeFib[i - 1].first;
		tmp.second = storeFib[i - 2].second + storeFib[i - 1].second;
		storeFib.push_back(tmp);
	}
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testcase;
	int input;
	vector<pair<int, int>> storeFib;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		cin >> input;
		fib(input, storeFib);
		cout << storeFib[input].first << " " << storeFib[input].second << "\n";
		storeFib.clear();
	}

	return 0;
}
