
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
int v[10010], w[10010];
int f[10010];
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);

	cout << f[m];
	return 0;
}
