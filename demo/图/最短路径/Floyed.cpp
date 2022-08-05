

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int g[MAXN][MAXN]; //状态数组(存最短路径)
int n = 0; //点的个数
int m = 0; //边的个数
void init(){
    memset(g,0x7f,sizeof(g));  //初始化
}

void Floyed(){
    for(int k = 1;k <= n;k++){//中转点
        for(int i = 1;i <= n;i++){//起始点
            for(int j = 1;j <= n;j++){//结束点
                if(i != j && j != k && i != k){ //不是自己走自己
                    g[i][j] = min(g[i][j],g[i][k] + g[k][j]); //最短=min(原最短,起始点到中转点最短+中转点到结束点最短)
                }
            }
        }
    }
}

void WriteOut(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(g[i][j] > 0x3fffff){ //是否为正无穷（不能走到）
                cout << "N ";
            }else{
                cout << g[i][j] << " ";
            }
        }
        cout << endl;
    }
    return;
}

int main(){
    init();
    cin >> n;
    cin >> m;
    for(int i = 1;i <= m;i++){
        int from;
        int to;
        int w;
        cin >> from >> to >> w;
        g[from][to] = min(g[from][to],w);
        //无向图适用
        //g[from][to] = min(g[from][to],w);
    }
    Floyed();
    WriteOut();
    return 0;
}