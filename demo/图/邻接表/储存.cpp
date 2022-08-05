/*
{1,2,10}{1,3,7}{3,4,9}{2,3,8}{2,4,12}{1,2,7}

*/

// for demo only

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

struct edge
{
    int to;
    int w;
    int next;
};

int head[MAXN] = {0};
int tail[MAXN] = {0};
edge _edge[MAXN] = {0};
int numtimer = 0;
void AddEdge(int from, int to, int w)
{
    numtimer++;
    _edge[numtimer].next = head[from];
    _edge[numtimer].next = to;
    _edge[numtimer].w = w;
    head[from] = numtimer;
}

int main()
{
}