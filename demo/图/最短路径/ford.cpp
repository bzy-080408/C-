//bug:输出0



#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define MAX_FLOAT_NUM 0x3f


int dis[MAXN];        //原点v到i的距离
bool flag[MAXN]; //求解标记
int preload[MAXN];   //上一个点
int w[MAXN][MAXN];   //权值
int v;
int n;
int m;
int start;
int last;

void debug_flag(){ 
    cout << "debug:";               //print flag(for debug only)
    for(int i = 0;i < n;i++){
        if(flag[i]){
            cout << "Y" <<" ";
        }else{
            cout << "N ";
        }
    }
}

void init(){
    memset(dis,0x7f,sizeof(dis));
    dis[v] = 0;
}


void Dijstra(){
    int minx;
    int k = 0; // 中转点
    dis[start] = 0;
    for(int i = 1;i <= n;i++){
        for(int i = 1;i <= n;i++){
            if(dis[w[j][1]])
        }
    }
    //debug_flag();
}

int main(){
    cin >> n >> m; //顶点数，边数
    for(int i = 1;i <= m;i++){
        int v1,v2,d;
        cin >> v1 >> v2 >> d;
        w[v1][v2] = min(d,w[v1][v2]);
        w[v1][v2] = min(d,w[v1][v2]);
    }
    cin >> start >> last;
    v = start;
    Dijstra();
    cout << dis[last];
    return 0;
}