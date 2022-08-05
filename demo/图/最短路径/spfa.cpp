

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

struct GraphEdge
{
    int w;
    int to;
    int next;
};

GraphEdge edge[MAXN];
priority_queue<pair<int, int>> _pque; //中转点队列
int head[MAXN];
bool vis[MAXN];
bool flag[MAXN];
int dis[MAXN];
int GraphTimer;
int n;
int m;
int start;

void init()     //多次查询使用
{
    while (!_pque.empty())
    {
        _pque.pop();
    }
    memset(head, 0, sizeof(head));
    memset(vis, false, sizeof(vis));
    memset(flag, false, sizeof(flag));
    memset(dis, 0x3f, sizeof(dis));
    memset(edge, 0, sizeof(edge));
}

void AddEdge(int from, int to, int w)
{
    GraphTimer++;
    edge[GraphTimer].to = to;
    edge[GraphTimer].w = w;
    edge[GraphTimer].next = head[from];
    head[from] = GraphTimer;
}

void SPFA()
{
    while (!_pque.empty())
    {
        int k = _pque.top().second; //设置中转点为最小节点编号
        _pque.pop();                //最小节点出队列
        if (!flag[k])
        {
            flag[k] = true;
            for (int i = head[k]; i != 0; i = edge[i].next)
            {
                int nto = edge[i].to;
                int nw = edge[i].w;
                if (dis[k] + nw < dis[nto])
                {
                    dis[nto] = dis[k] + nw;
                    _pque.push(make_pair(-1 * dis[nto], nto));
                }
            }
        }
    }
}

int main()
{
    int from;
    int to;
    int w;
    cin >> n >> m; //顶点数量，边数量
    for (int i = 1; i <= m; i++)
    {
        cin >> from >> to >> w;
        AddEdge(from, to, w);
        //无向图适用
        // AddEdge(to,from,w);
    }
    start = 1;
    SPFA();
    //cout << dis[2];
    return 0;
}