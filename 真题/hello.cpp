

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int sum[m + 1][n + 1];
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			cin >> sum[i][j];
		}
	}
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			sum[i][j] = max(sum[i][j - 1], sum[i - 1][j]);
		}
	}
	int out = 0;
	for (int i = 0; i < m; i++)
	{
		out = max(out, sum[0][i + 1]);
	}
	cout << sum[m][n];
	return 0;
}