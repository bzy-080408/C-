

#include <bits/stdc++.h>

namespace bzy
{
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
        int GraphTimer;
        void build(int point_sum)
        { //构建n个顶点的图
            for (int i = 0; i <= point_sum; i++)
            {
                head.push_back(0);
            }
            GraphEdge tmp;
            edge.push_back(tmp);
            return;
        }

        void clear()
        {
            edge.clear();
            head.clear();
            GraphTimer = 0;
            return;
        }

        void AddEdge(int from, int to, int w)
        {
            GraphEdge tmp;
            edge.push_back(tmp);
            GraphTimer++;
            edge[GraphTimer].to = to;
            edge[GraphTimer].w = w;
            edge[GraphTimer].next = head[from];
            head[from] = GraphTimer;
            return;
        }
        inline void Dijstra(int dis[])
        {
            memset(dis, 0x3f, sizeof(dis));
            priority_queue<pair<int, int>> _pque;
            bool flag[GraphTimer];
            while (!_pque.empty())
            {
                int k = _pque.top().second; //设置中转点为最小节点编号
                _pque.pop();                //最小节点出队列
                if (!flag[k])
                {
                    flag[k] = true;
                    for (int i = head[k]; i != 0; i = edge[i].next)
                    {
                        int nto = edge[i].to;
                        int nw = edge[i].w;
                        if (dis[k] + nw < dis[nto])
                        {
                            dis[nto] = dis[k] + nw;
                            _pque.push(make_pair(-1 * dis[nto], nto));
                        }
                    }
                }
            }
            return;
        }
    };
    struct bcj
    {
        struct Tree
        {
            int x;
            int y;
            int z; // w
        };
        vector<int> _fa;       //祖先是谁
        vector<Tree> TreeEdge; //最小生成树的Edge
        void make(int n)
        { //初始化
            TreeEdge.clear();
            _fa.clear();
            Tree tmp;
            TreeEdge.push_back(tmp);
            for (int i = 0; i <= n; i++)
            {
                _fa.push_back(i);
            }
        }

        int Find(int x)
        { //找祖先
            if (x == _fa[x])
            {
                return x;
            }
            else
            {
                return _fa[x] = Find(_fa[x]);
            };
        }

        void Unionn(int x, int y)
        { //合并
            x = Find(x);
            y = Find(y);
            _fa[y] = x;
        }

        bool Judge(int x, int y)
        { //检查是否属于同一个集合
            x = Find(x);
            y = Find(y);
            if (x == y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int allsum()
        {
            int out = 0;
            for (int i = 1; i <= sizeof(_fa); i++)
            {
                if (_fa[i] == i)
                {
                    out++;
                }
            }
            return out;
        }
        static bool MIN_BUILD_TREE_CMP(Tree a, Tree b)
        {
            return a.z < b.z;
        }
        void TREE_ADD_EDGE(int x, int y, int w)
        {
            Tree tmp;
            tmp.x = x, tmp.y = y, tmp.z = w;
            TreeEdge.push_back(tmp);
        }
        int MinBuildTree()
        {
            int ans = 0;
            sort(TreeEdge.begin() + 1, TreeEdge.end() + 1, MIN_BUILD_TREE_CMP);
            for (int i = 1; i <= sizeof(TreeEdge); i++)
            { // from small to big
                int x = Find(TreeEdge[i].x);
                int y = Find(TreeEdge[i].y); // find father
                if (x != y)
                {
                    _fa[y] = x; // update father
                    ans += TreeEdge[i].z;
                }
            }
            return ans;
        }
    };
}