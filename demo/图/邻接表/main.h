//图的邻接表表示
//O(n) W(3n)


#include <bits/stdc++.h>

struct GraphEdge{
    int to;
    int w;
    int next;
};

void AddEdge(int from,int to,int w,GrapgEdge &edge,int &head,int &GraphTimer){
    GraphTimer++;
    edge[GraphTimer].next = head[from];
    edge[GraphTimer].to = to;
    edge[GraphTimer].w = w;
    head[from] = GraphTimer;
}
