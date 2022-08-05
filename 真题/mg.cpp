

#include <bits/stdc++.h>

using namespace std;

int m[101][101] = {0};
int X, Y, SX, SY, n;
int PD(int x, int y, bool UD)
{
    if (x = X && y == Y)
    {
        return 1;
    }
    if (m[x][y + 1] == 0)
    {
        return PD(x, y + 1, false);
    }
    if (m[x][y - 1] == 0)
    {
        // m[x][y - 1] = 2;
        return PD(x, y - 1, false);
    }
    if (UD)
    {
        return PD(x - 1, y, true);
    }
    else
    {
        if (m[x + 1][y] == 0 && x <= n)
        {
            return PD(x + 1, y, false);
        }
        else
        {
            m[x][y] = 1;
            return PD(x, y, true);
        }
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            m[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[i][j];
        }
    }
    cin >> SX >> SY >> X >> Y;
    if (PD(SX, SY, false))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}