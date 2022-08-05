

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define MAXM 50000

struct Tree
{
    int x;
    int y;
    int z; // w
} edge[MAXM];

int _fa[MAXN] = {0};
int n;
int m;
int ans;

void make()
{
    for (int i = 1; i <= n; i++)
    {
        _fa[i] = i;
    }
}

int Find(int x)
{
    if (x == _fa[x])
    {
        return x;
    }
    else
    {
        return _fa[x] = Find(_fa[x]);
    };
}

void Unionn(int x, int y)
{ //合并
    x = Find(x);
    y = Find(y);
    _fa[y] = x;
}

bool Judge(int x, int y)
{ //检查是否属于同一个集合
    x = Find(x);
    y = Find(y);
    if (x == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int allsum()
{
    int out = 0;
    for (int i = 1; i <= n; i++)
    {
        if (_fa[i] == i)
        {
            out++;
        }
    }
    return out;
}

bool cmp(Tree a, Tree b)
{
    return a.z < b.z;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> edge[i].x >> edge[i].y >> edge[i].z;
    }
    sort(edge, edge + m + 1, cmp);
    make();
    for (int i = 1; i <= m; i++)
    { // from small to big
        int x = Find(edge[i].x);
        int y = Find(edge[i].y); // find father
        if (x != y)
        {
            _fa[y] = x; // update father
            ans += edge[i].z;
        }
    }
    cout << ans;
    return 0;
}
