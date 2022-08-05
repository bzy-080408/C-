

#include <bits/stdc++.h>

using namespace std;

int sum[20][20];
int tmp = 1;

int chick(int x, int y)
{
    if (sum[x][y + 1] == -1)
    {
        sum[x][y + 1] = tmp;
        tmp++;
        return chick(x, y + 1);
    }
    if (sum[x - 1][y] == -1)
    {
        sum[x - 1][y] = tmp;
        tmp++;
        return chick(x - 1, y);
    }
    if (sum[x][y - 1] == -1)
    {
        sum[x][y - 1] = tmp;
        tmp++;
        return chick(x, y - 1);
    }
    if (sum[x + 1][y] == -1)
    {
        sum[x + 1][y] = tmp;
        tmp++;
        return chick(x + 1, y);
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // int sum[n + 2][m + 2] = {0};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[j][i] = -1;
        }
    }
    // int tmp = 1;
    chick(0, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << setw(3) << sum[i][j];
        }
        cout << endl;
    }
    return 0;
}