//WA

#include <bits/stdc++.h>

#define MAXN 1001
#define MAXM 1000001

using namespace std;

struct Edge{
    int w;
    int next;
    int to;
};

Edge edge[MAXN];
int n;
//int q[MAXN][MAXN]; //邻接矩阵
int minn[MAXM];	   // minn表示不在最小生成树中的点与在最小生成树中的点相连的最小边权
int ans;
bool f[MAXM]; //不在最小生成树中的点f等于false，在就等于true (vis[])
int head[MAXN];
int GraphTimer;


void AddEdge(int from, int to, int w)
{
    GraphTimer++;
    edge[GraphTimer].to = to;
    edge[GraphTimer].w = w;
    edge[GraphTimer].next = head[from];
    head[from] = GraphTimer;
}

void init_all(){
	memset(head,0,sizeof(head));
    memset(edge,0,sizeof(edge));
	memset(minn,0x3f,sizeof(minn));
	memset(f,0,sizeof(f));
	ans = 0;
	n = 0;
	minn[1] = 0;
}

void init_first(){
	memset(minn,0x3f,sizeof(minn));
	minn[1] = 0;
}

void ParseIn(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp = 0;
            cin >> tmp;
            if(i == j){
                continue;
            }else{
                AddEdge(i,j,tmp);
            }
		}
	}
}

void Prim(){
	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!f[j] && minn[j] < minn[k]) //寻找权值最短的边（且不能是已经在最小生成树中的点）
			{
				k = j;
			}
		}
		f[k] = true; //把它加入最小生成树
		for (int j = head[k]; j != 0; j = edge[j].next)
		{
			if (!f[j] && edge[j].w < minn[j]) //利用新点改变其他不在最小生成树中的点的边的权值
			{
				minn[j] = edge[j].w;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans += minn[i]; //把所有在最小生成树中的点的权值加起来
	}
}

void WriteOut(){
	printf("%d", ans);
}

int main()
{
	init_first();
	ParseIn();
	Prim();
	WriteOut();
	return 0;
}