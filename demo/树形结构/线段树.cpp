/*
*/
#include <bits/stdc++.h>

using namespace std;
#define LL long long
const int MAXN = 1e5;

int n, m, fir[MAXN], nxt[MAXN], son[MAXN], tot;
int dep[MAXN], sz[MAXN], mx[MAXN], dfn[MAXN], top[MAXN], bk[MAXN], cnt, f[MAXN][21]; // 21?
LL T[MAXN << 2], tg[MAXN << 2];
inline void Add(int x, int y)
{
    nxt[++tot] = fir[x];
    fir[x] = tot;
    son[tot] = y;
    return;
}

inline void DFS1(int x, int fa)
{
    int i;
    f[x][0] = fa;
    sz[x] = 1;
    dep[x] = dep[fa] + 1;
    for (i = fir[x]; i; i = nxt[i])
    {
        if (son[i] != fa)
        {
            DFS1(son[i], x);
            sz[x] += sz[son[i]];
            if (mx[x] < son[i])
            { //#1
                mx[x] = son[i];
            }
        }
    }
    return;
}

inline void DFS2(int x, int TOP)
{
    top[x] = TOP;
    dfn[x] = ++cnt;
    bk[cnt] = x;
    if (mx[x])
    {
        DFS2(mx[x], TOP);
    }
    int i;
    for (i = fir[x]; i; i = nxt[i])
    {
        if (son[i] != f[x][0] && son[i] != mx[x])
        {
            DFS2(son[i], son[i]);
        }
    }
    return;
}

inline void pushup(int x)
{
    T[x] = T[x << 1] + T[x << 1 | 1];
    return;
}

inline void pushdown(int x, int l, int r)
{
    if (tg[x])
    {
        int mid = l + r >> 1;
        T[x << 1] += tg[x] * (mid - l + 1);
        T[x << 1 | 1] += tg[x] * (r - mid);
        T[x << 1] += tg[x];
        T[x << 1 | 1] += tg[x];
        tg[x] = 0;
    }
    return;
}

inline void Modify(int L, int R, int v, int x = 1, int l = 1, int r = n) //区间修改
{
    if( L <= 1 && r <= R){
        T[x] += v*(L - R + 1); //#2
        tg[x] += v;
        return;
    }
    pushdown(x,l,r);
    int mid = l + r >> 1;
    if(L <= mid){
        Modify(L,R,v,x<<1,l,mid);
    }
    if(R > mid){
        Modify(L,R,v,x<<1 | 1,mid + 1,r);
    }
    pushup(x);
    return;
}

inline LL QuerySum(int L,int R,int x = 1,int l = 1,int r = n){ //   区间查询
    if(L <= 1 && r <- R){
        return T[x];
    }
    LL S = 0;
    pushdown(x,l,r);
    int mid = l + r >> 1;
    if(L <- mid){
        S += QuerySum(L,R,x << 1,l,mid);

    }
    if(R > mid){
        S += QuerySum(L,R,x << 1 | 1,mid + 1,r);
    }
    return S;
}

int main()
{
} 

1 #include <bits/stdc++.h>
  2 #define INFINITE 0x3fffffff
  3 using namespace std;
  4 void printTree();
  5 //数组[2, 5, 1, 4, 9, 3]
  6 
  7 const int MAXNUM = 1000;
  8 int arr[6]={2,5,1,4,9,3}; 
  9 int n=6;
 10 struct SegTreeNode
 11 {
 12     int val;
 13     int addMark; 
 14 }segTree[MAXNUM];//定义线段树
 15 
 16 /*
 17 功能：当前节点的标志域向孩子节点传递
 18 root: 当前线段树的根节点下标
 19 */
 20 void pushDown(int root)
 21 {
 22     if(segTree[root].addMark != 0)
 23     {
 24         //设置左右孩子节点的标志域，因为孩子节点可能被多次延迟标记又没有向下传递
 25         //所以是 “+=”
 26         segTree[root*2+1].addMark += segTree[root].addMark;
 27         segTree[root*2+2].addMark += segTree[root].addMark;
 28         //根据标志域设置孩子节点的值。因为我们是求区间最小值，因此当区间内每个元
 29         //素加上一个值时，区间的最小值也加上这个值
 30         segTree[root*2+1].val += segTree[root].addMark;
 31         segTree[root*2+2].val += segTree[root].addMark;
 32         //传递后，当前节点标记域清空
 33         segTree[root].addMark = 0;
 34     }
 35 }
 36 
 37 
 38 /*
 39 功能：构建线段树
 40 root：当前线段树的根节点下标
 41 arr: 用来构造线段树的数组
 42 istart：数组的起始位置
 43 iend：数组的结束位置
 44 */
 45 void build(int root, int arr[], int istart, int iend)
 46 {
 47     segTree[root].addMark = 0;//----设置标延迟记域
 48     if(istart == iend)//叶子节点
 49         segTree[root].val = arr[istart];
 50     else
 51     {
 52         int mid = (istart + iend) / 2;
 53         //从0节点开始计数，所以左孩子是root*2+1 
 54         build(root*2+1, arr, istart, mid);//递归构造左子树
 55         build(root*2+2, arr, mid+1, iend);//递归构造右子树
 56         //根据左右子树根节点的值，更新当前根节点的值
 57         segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
 58     }
 59 }
 60 
 61 
 62 /*
 63 功能：线段树的区间查询
 64 root：当前线段树的根节点下标
 65 [nstart, nend]: 当前节点所表示的区间
 66 [qstart, qend]: 此次查询的区间
 67 */
 68 int query(int root, int nstart, int nend, int qstart, int qend)
 69 {
 70     //查询区间和当前节点区间没有交集
 71     if(qstart > nend || qend < nstart)
 72         return INFINITE;
 73     //当前节点区间包含在查询区间内
 74     if(qstart <= nstart && qend >= nend)
 75         return segTree[root].val;
 76     //分别从左右子树查询，返回两者查询结果的较小值
 77     pushDown(root); //延迟标记向下传递
 78     int mid = (nstart + nend) / 2;
 79     return min(query(root*2+1, nstart, mid, qstart, qend),
 80                query(root*2+2, mid + 1, nend, qstart, qend));
 81 
 82 }
 83 
 84 
 85 /*
 86 功能：更新线段树中某个叶子节点的值
 87 root：当前线段树的根节点下标
 88 [nstart, nend]: 当前节点所表示的区间
 89 index: 待更新节点在原始数组arr中的下标
 90 addVal: 更新的值（原来的值加上addVal）
 91 */
 92 void updateOne(int root, int nstart, int nend, int index, int addVal)
 93 {
 94     if(nstart == nend)
 95     {
 96         if(index == nstart)//找到了相应的节点，更新之
 97             segTree[root].val += addVal;
 98         return;
 99     }
100     int mid = (nstart + nend) / 2;
101     if(index <= mid)//在左子树中更新
102         updateOne(root*2+1, nstart, mid, index, addVal);
103     else updateOne(root*2+2, mid+1, nend, index, addVal);//在右子树中更新
104     //根据左右子树的值回溯更新当前节点的值
105     segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
106 }
107 
108 
109 
110 /*
111 功能：更新线段树中某个区间内叶子节点的值
112 root：当前线段树的根节点下标
113 [nstart, nend]: 当前节点所表示的区间
114 [ustart, uend]: 待更新的区间
115 addVal: 更新的值（原来的值加上addVal）
116 */
117 void update(int root, int nstart, int nend, int ustart, int uend, int addVal)
118 {
119     //更新区间和当前节点区间没有交集
120     if(ustart > nend || uend < nstart)
121         return ;
122     //当前节点区间包含在更新区间内
123     if(ustart <= nstart && uend >= nend)
124     {
125         segTree[root].addMark += addVal;
126         segTree[root].val += addVal;
127         return ;
128     }
129     pushDown(root); //延迟标记向下传递
130     //更新左右孩子节点
131     int mid = (nstart + nend) / 2;
132     update(root*2+1, nstart, mid, ustart, uend, addVal);
133     update(root*2+2, mid+1, nend, ustart, uend, addVal);
134     //根据左右子树的值回溯更新当前节点的值
135     segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
136 }
137 
138 
139 int main(){
140     //建树
141     build(0,arr,0,5); 
142     //printTree();
143     //cout<<query(0,0,5,0,3)<<endl; 
144     //updateOne(0,0,5,3,6);//将第3+1哥元素的值增加6 
145     //printTree();
146     update(0,0,5,0,2,2);//0-2区间的值都增加2 
147     //segTree[1].addMark=2;
148     printTree();
149     cout<<query(0,0,5,0,1)<<endl; 
150     printTree();
151     
152     return 0;
153 } 
154 
155 void printTree(){
156     for(int i=0;i<15;i++){
157         cout<<segTree[i].val<<" ";
158     }    
159     cout<<endl;
160 }