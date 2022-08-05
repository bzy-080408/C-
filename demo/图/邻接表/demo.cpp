

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

// bfs:
queue<int> que;
void BFS()
{
    que.push(1);
    vis[1] = true;
    int h = 0;
    while (!que.empty())
    {
        h = que.front();
        que.pop();
        cout << h << " ";
        for (int i = head[h]; i != 0; i = edge[i].next)
        {
            int y = edge[i].to;
            if (!vis[y])
            {
                vis[y] = true;
                que.push(y);
            }
        }
    }
}

int main()
{
    cin >> n >> m; // n:边数，m：顶点数
    for (int i = 0; i < n; i++)
    {
        int to;
        int from;
        int w;
        cin >> from >> to >> w;
        AddEdge(from, to, w);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = head[i]; j != 0; j = edge[j].next)
        {
            cout << i << "->" << edge[j].to << "sum:" << edge[j].w << endl;
        }
    }
    return 0;
}