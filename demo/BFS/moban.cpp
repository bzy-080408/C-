

#include <bits/stdc++.h>

using namespace std;

int n = 110, m = 110;
int que[10100][3];
int _map[110][110];
int head, tail;
int tox[12] = {1, 1, 2, 2, 2, 2, -1, -1, -2, -2, -2, -2};
int toy[12] = {-2, 2, -2, -1, 1, 2, -2, 2, -1, 1, -2, 2};

void bfs(int _x, int _y)
{
    int x, y, cx, cy;
    que[1][1] = _x;
    que[1][2] = _y;
    _map[_x][_y] = 1;
    head = 1;
    tail = 1;
    while (tail >= head)
    {
        x = que[head][1];
        y = que[head][2];
        for (int i = 0; i <= 12; i++)
        {
            cx = x + tox[i];
            cy = y + toy[i];
            if (cx >= 1 && cx <= n && cy >= 1 && cy <= m)
            {
                tail++;
                que[tail][1] = cx;
                que[tail][2] = cy;
                _map[cx][cy] = min(tail, _map[cx][cy]);
            }
        }
        head++;
    }
}

int main()
{
    int a = 0, b = 0;
    memset(_map, 0x7ff, sizeof(_map));
    cin >> a >> b;
    bfs(a, b);
    cout << _map[1][1];
    memset(que, 0, sizeof(que));
    memset(_map, 0x7ff, sizeof(_map));
    cin >> a >> b;
    bfs(a, b);
    cout << _map[1][1];
    return 0;
}