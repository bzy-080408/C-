

#include <bits/stdc++.h>

using namespace std;

int n = 0, m = 0;
struct a
{
    int x, y;
} ;
queue<a> que;
int _map[110][110];
int _head, tail;
int tox[4] = {0, 0, 1, -1};
int toy[4] = {1, -1, 0, 0};

void bfs()
{
    int x, y, cx, cy;
    que.push((a){1,1});
    _map[1][1] = 1;
    while (!que.empty())
    {
        a head = que.front();
        for (int i = 0; i <= 3; i++)
        {
            cx = head.x + tox[i];
            cy = head.y + toy[i];
            if (cx >= 1 && cx <= n && cy >= 1 && cy <= m && _map[cx][cy] == 0)
            {
                tail++;
                //que.push()
                _map[cx][cy] = tail;
            }
        }
        _head++;
    }
}

int main()
{
    cin >> m >> n;
    bfs();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << _map[i][j];
        }
        cout << endl;
    }
    return 0;
}