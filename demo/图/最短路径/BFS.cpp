

#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

struct GraphEdge{
    //int w;
    int to;
    int next;
};

int n,m;
int GraphTimer;
int head[MAXN];
GraphEdge edge[MAXN];
queue<int> _que;
int start = 1;
int out = 0;
int minn[MAXN];
bool f[MAXN];
void AddEdge(int from, int to)
{
    GraphTimer++;
    edge[GraphTimer].to = to;
    edge[GraphTimer].next = head[from];
    head[from] = GraphTimer;
}
void BFS(){
    int h = 0;
    minn[start] = 0;
    _que.push(start);
    f[start] = true;
    while(_que.size()){
        h = _que.front();
        _que.pop();
        for(int i = head[h];i != 0;i = edge[i].next){
            int y = edge[i].to;
            if(minn[y] != 0){
                continue;
            }
            minn[y] = minn[h] + 1;
            _que.push(y);
        }
    }
}

void ParseIn(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int from,to;
        cin >> from >> to;
        AddEdge(from,to);
    }
}

int main(){
    ParseIn();
    BFS();
    for(int i = 2;i <= n;i++){
        cout << minn[i] << " ";
    }
    return 0;
}