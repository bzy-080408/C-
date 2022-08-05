

#include <bits/stdc++.h>
using namespace std;

struct GraphEdge
{
    int w;
    int to;
    int next;
};

struct graph
{
    vector<GraphEdge> edge;
    vector<int> head;
    void build(int sum){
        for(int i = 0;i <= sum;i++){
            head.push_back(0);
        }
    }
    int GraphTimer;
    int n = 0, m = 0;
    void AddEdge(int from, int to, int w)
    {
        GraphTimer++;
        GraphEdge tmp;
        tmp.to = to;
        tmp.w = w;
        tmp.next = head[from];
        edge.push_back(tmp);
        head[from] = GraphTimer;
    }
};
