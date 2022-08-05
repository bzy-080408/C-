

#include <bits/stdc++.h>

#define MAXN 1001
#define MAXM 1000001

using namespace std;

int n;
int q[MAXN][MAXN]; //邻接矩阵
int minn[MAXM];	   // minn表示不在最小生成树中的点与在最小生成树中的点相连的最小边权
int ans;
bool f[MAXM]; //不在最小生成树中的点f等于false，在就等于true (vis[])

void init_all(){
	memset(q,0,sizeof(q));
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
			scanf("%d", &q[i][j]); //输入邻接矩阵
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
		for (int j = 1; j <= n; j++)
		{
			if (!f[j] && q[k][j] < minn[j]) //利用新点改变其他不在最小生成树中的点的边的权值
			{
				minn[j] = q[k][j];
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