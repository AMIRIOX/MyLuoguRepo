#ifdef FLOYD_METHOD_40PTS
#include <iostream>
using namespace std;
int G[5000][5000];
int s, e, n, m, b;
const int meta = 1;
int main(void)
{
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        G[x][y] = min(G[x][y], v);
        G[y][x] = min(G[y][x], v);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
    for (int i = 1; i <= b; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", G[x][1] + G[1][y]);
    }
    return 0;
}
#endif

#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
const int maxn = 50000*4;
const int maxm = 100000*2;
int vis[maxn], dis[maxn];
typedef pair<int, int> P;
struct edge
{
    int to, w, nxt;
    edge() { nxt = 0; }
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w)
{
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
struct node
{
    int u, dis;
    node(int _u, int _dis) : u(_u), dis(_dis) {}
    bool operator<(const node &o) const
    {
        return this->dis > o.dis;
    }
};
void dijkstra(/*int s, int e*/)
{
    priority_queue<node> q;
    q.push(node(1, 0));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        if (vis[x.u])
            continue;
        vis[x.u] = 1;
        for (int i = head[x.u]; i; i = g[i].nxt)
        {
            int y = g[i].to;
            if (dis[y] > dis[x.u] + g[i].w)
                dis[y] = dis[x.u] + g[i].w;
            if (!vis[y])
                q.push(node(y, dis[y]));
        }
    }
    // return P(dis[s],dis[e]);
}
int main(void)
{
    int n, m, b;
    scanf("%d %d %d", &n, &m, &b);
    // printf("n,m,b input ok\n");
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        addEdge(x, y, v);
        addEdge(y, x, v);
    }
    // printf("edges input ok\n");
    dijkstra();
    for (int i = 1; i <= b; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", dis[x]+dis[y]);
        // int ax,ay;
        // tie(ax,ay)=dijkstra(x, y);
        // printf("%d\n", ax+ay);
    }
    return 0;
}