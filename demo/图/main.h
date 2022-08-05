

#include <bits/stdc++.h>

using namespace std;

namespace graph
{
    struct GraphEdge
    {
        int w;
        int to;
        int next;
    };
    GraphEdge edge[MAXN];
    int head[MAXN];
    int GraphTimer;
    int n = 0, m = 0;
    bool vis[MAXN] = {false};
    void AddEdge(int from, int to, int w)
    {
        GraphTimer++;
        edge[GraphTimer].to = to;
        edge[GraphTimer].w = w;
        edge[GraphTimer].next = head[from];
        head[from] = GraphTimer;
    }
    // void clean(GraphEdge){}
    void DFS(int x)
    {
        vis[x] = true;
        for (int j = head[j]; j != 0; j = edge[j].next)
        {
            int y = edge[j].to;
            if (!vis[y])
            {
                cout << y << " ";
                DFS(y);
            }
        }
        vis[x] = true;
        return;
    }

    queue<int> BFS_QUEUE;
    void BFS(int a)
    {
        BFS_QUEUE.push(a);
        vis[a] = true;
        int h = 0;
        while (!BFS_QUEUE.empty())
        {
            h = BFS_QUEUE.front();
            que.pop();
            // cout << h << " ";
            for (int i = head[h]; i != 0; i = edge[i].next)
            {
                int y = edge[i].to;
                if (!vis[y])
                {
                    vis[y] = true;
                    BFS_QUEUE.push(y);
                }
            }
        }
    }
}

namespace bcj
{
    // int _fa[MAXN];
    // int n = 0; //元素个数
    // int m = 0; //操作个数
    struct Tree
    {
        int x;
        int y;
        int z; // w
    };
    inline void make(int n, int &_fa[])
    { //初始化
        for (int i = 1; i <= n; i++)
        {
            _fa[i] = i;
        }
    }

    inline int Find(int x, int &_fa[])
    { //找祖先
        if (x == _fa[x])
        {
            return x;
        }
        else
        {
            return _fa[x] = Find(_fa[x], _fa);
        };
    }

    inline void Unionn(int x, int y, int &_fa[])
    { //合并
        x = Find(x, _fa);
        y = Find(y, _fa);
        _fa[y] = x;
    }

    inline bool Judge(int x, int y, int &_fa[])
    { //检查是否属于同一个集合
        x = Find(x, _fa);
        y = Find(y, _fa);
        if (x == y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline int allsum(const int &fa[])
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
    int MinMakeTree(const int m, Tree &edge)
    {
        int ans = 0;
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
        return ans;
    }
}

namespace kahn
{
    struct GraphEdge
    {
        int w;
        int to;
        int next;
    };

    void TuoPu(const int n, const int m, GraphEdge &edge[], int &head[])
    {
        for (int i = 0; i < m; i++)
        {
            rudu[edge[i].to]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (rudu[i] == 0)
            {
                graph_que.push(i); //入度为0的顶点入队
            }
        }
        while (graph_que.size())
        {                              //若队列不为空
            int x = graph_que.front(); //取队头，优先队列改为.top
            cout << x << " ";
            graph_que.pop();
            for (int i = head[x]; i != 0; i = edge[i].next)
            {
                int y = edge[i].to;
                rudu[y]--;
                if (rudu[y] == 0)
                {
                    graph_que.push(y);
                }
            }
        }
        return;
    }
}

namespace Dijstra_queue
{
#define MAXN 2000
    struct GraphEdge
    {
        int w;
        int to;
        int next;
    };
    priority_queue<pair<int, int>> _pque; //中转点队列
    bool flag[MAXN];
    int dis[MAXN];
    int start;
    int last;
    // void init() //多次查询使用
    // {
    //     priority_queue<pair<int, int>> tmp_del;
    //     swap(tmp_del,_pque);
    //     memset(flag, false, sizeof(flag));
    //     memset(dis, 0x3f, sizeof(dis));
    //     _pque.push(make_pair(0, start));
    //     dis[start] = 0;
    //     return;
    // }

    void init_first(const int n, int &dis[])
    {
        memset(dis, 0x3f, sizeof(dis));
        _pque.push(make_pair(0, start));
        dis[start] = 0;
        return;
    }

    void Dijstra(const int n, const int &head[], int &dis[])
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

}

namespace Floyed
{
    void Floyed(const int n, int &g[][])
    {
        for (int k = 1; k <= n; k++)
        { //中转点
            for (int i = 1; i <= n; i++)
            { //起始点
                for (int j = 1; j <= n; j++)
                { //结束点
                    if (i != j && j != k && i != k)
                    {                                              //不是自己走自己
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]); //最短=min(原最短,起始点到中转点最短+中转点到结束点最短)
                    }
                }
            }
        }
        return;
    }
}