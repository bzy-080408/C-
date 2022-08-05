

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
queue<int> graph_que; //注意优先队列优化/使用
int head[MAXN];
int rudu[MAXN];
int GraphTimer;
int n;
int m;

void AddEdge(int from, int to, int w)
{
    GraphTimer++;
    edge[GraphTimer].to = to;
    edge[GraphTimer].w = w;
    edge[GraphTimer].next = head[from];
    head[from] = GraphTimer;
    return;
}

void ParseIn(){
    int ParseIn_from;
    int ParseIn_to;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> ParseIn_from >> ParseIn_to;
        AddEdge(ParseIn_from, ParseIn_to, 0);
        rudu[ParseIn_to]++;
    }
}

void TuoPu()
{
    for (int i = 1; i <= n; i++)
    { 
        if (rudu[i] == 0)
        {
            graph_que.push(i);  //入度为0的顶点入队
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

int main()
{
    ParseIn();
    TuoPu();
    return 0;
}