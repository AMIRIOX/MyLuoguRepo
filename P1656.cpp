// first code: disjoint set.

#ifdef DISJOINT_SET_METHOD
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int fa[maxn], n, m, ans;

struct edge
{
    int u, v;
} e[maxn], ansv[maxn];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void unite(int a, int b)
{
    int ai = find(a);
    int bi = find(b);
    if (ai != bi)
        fa[ai] = bi;
}
void check(int u)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        if (i != u && find(e[i].u) != find(e[i].v))
            unite(e[i].u, e[i].v);
    for (int headx = find(1), i = 2; i <= n; i++)
        if (find(i) != headx)
        {
            ansv[++ans].u = min(e[u].u, e[u].v);
            ansv[ans].v = max(e[u].u, e[u].v);
            break;
        }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &e[i].u, &e[i].v);
    for (int i = 1; i <= m; i++)
        check(i);
    sort(ansv + 1, ansv + ans + 1, [&](edge &a, edge &b) {if(a.u==b.u) return a.v<b.v; else return a.u<b.u; });
    for (int i = 1; i <= ans; i++)
    {
        printf("%d %d\n", ansv[i].u, ansv[i].v);
    }
    return 0;
}
#endif

#ifdef DIJKSTRA_METHOD
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct edge
{
    int to, w, nxt;
    edge() { nxt = -1; }
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w)
{
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
struct pureEdge
{
    int u, v;
    bool operator<(const pureEdge &o) const
    {
        if (this->u == o.u)
            return this->v < o.v;
        else
            return this->u < o.u;
    }
} e[maxn], ansv[maxn];
int ans;
struct node
{
    int u, dis;
    node(int _u, int _dis) : u(_u), dis(_dis) {}
    bool operator<(const node &o) const
    {
        return this->dis > o.dis;
    }
};
bool vis[maxn];
int dis[maxn];
void dijkstra(pureEdge dpe)
{
    priority_queue<node> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    int u = dpe.u, v = dpe.v;
    q.push(node(u, 0));
    dis[u] = 0;
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        if (vis[x.u])
            continue;
        vis[x.u] = true;
        for (int i = head[x.u]; ~i; i = g[i].nxt)
        {
            int y = g[i].to;
            if (x.u == u && y == v)
                continue;
            if (dis[y] > dis[x.u] + g[i].w)
                dis[y] = dis[x.u] + g[i].w;
            if (!vis[y])
                q.push(node(y, dis[y]));
        }
    }
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        e[i].u = x;
        e[i].v = y;
        addEdge(x, y, 1);
        addEdge(y, x, 1);
    }
    for (int i = 1; i <= m; i++)
    {
        dijkstra(e[i]);
        if (dis[e[i].v] > 500000)
        {
            ans++;
            ansv[ans].u = min(e[i].u, e[i].v);
            ansv[ans].v = max(e[i].u, e[i].v);
        }
    }
    sort(ansv + 1, ansv + ans + 1);
    for (int i = 1; i <= ans; i++)
    {
        printf("%d %d\n", ansv[i].u, ansv[i].v);
    }
    return 0;
}
#endif
#include <iostream>
using namespace std;
const int maxn = 1e4 + 10;
struct edge
{
    int to, w, nxt;
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w)
{
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
struct pure
{
    int u, v, dis;
} e[maxn], ans[maxn];
int bc;
pure del;

void dfs(int u) {
    
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        addEdge(x, y, v);
        addEdge(y, x, v);
        e[++bc].u = x;
        e[bc].v = y;
        e[bc].dis = v;
    }
    for(int i=1;i<=m;i++) {
        del=e[i];
        dfs(del.u);
    }
}