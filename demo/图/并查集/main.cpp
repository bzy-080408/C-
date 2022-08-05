

#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010 //最多元素

int _fa[MAXN];   //祖先是谁
int _long[MAXN]; //到祖先的长度
int n = 0;       //元素个数
int m = 0;       //操作个数

void make()
{ //初始化
    for (int i = 1; i <= n; i++)
    {
        _fa[i] = i;
    }
}

int Find(int x)
{ //找祖先
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

int get(int x, int &cnt)
{ // cnt记录环的长度
    cnt++;
    if (_fa[x] == x)
        return x;
    else
        return get(_fa[x], cnt);
}

int main()
{
    cin >> n >> m;
    make();
    for (int i = 1; i <= m; i++)
    {
        int z = 0, x = 0, y = 0;
        cin >> z >> x >> y;
        if (z == 1)
        {
            Unionn(x, y);
        }
        else
        {
            if (Judge(x, y))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}