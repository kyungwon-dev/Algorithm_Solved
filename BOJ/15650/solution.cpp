#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int num[10];
bool c[10];

void go(int start,int index,int n,int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; i++)
	{
		if (c[i])
			continue;
		c[i] = true;
		num[index] = i;
		go(i+1,index + 1, n, m);
		c[i] = false;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	go(1,0, n, m);
	return 0;
}