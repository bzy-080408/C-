

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
int pre[MAXN]; //记录前驱点(记录路径)
int GraphTimer;
int n;
int m;
int start;
int last;

void init() //多次查询使用
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
    _pque.push(make_pair(0, start));
    dis[start] = 0;
    return;
}

void init_first(){
    memset(dis,0x3f,sizeof(dis));
    _pque.push(make_pair(0, start));
    dis[start] = 0;
    return;
}

void AddEdge(int from, int to, int w)
{
    GraphTimer++;
    edge[GraphTimer].to = to;
    edge[GraphTimer].w = w;
    edge[GraphTimer].next = head[from];
    head[from] = GraphTimer;
}

void Dijstra()
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
    return;
}


void WriteOut(){
    for(int i = 1;i <= n;i++){
        cout << dis[i] << " ";
    }
}

int main()
{
    int from;
    int to;
    int w;
    cin >> n >> m; //顶点数量，边数量
    // cin >> start >> last; //起点，终点
    start = 1; // default
    init_first();
    for (int i = 1; i <= m; i++)
    {
        cin >> from >> to >> w;
        AddEdge(from, to, w);
        // 无向图适用
        AddEdge(to,from,w);
    }
    Dijstra();
    WriteOut();
    return 0;
    
}
