#include <cstdio>
#include <cstring>
const int maxn = 10010;
int dis[maxn];
bool vis[maxn];
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
void dfs(int now, int far, int val)
{
    printf("here is %d, my father is %d, now value is %d\n", now, far, val);
    if (vis[now])
        return;
    vis[now] = true;
    dis[now] = val;
    for (int i = head[now]; ~i; i = g[i].nxt)
    {
        if (g[i].to != far)
        {
            printf("dfs to %d\n", g[i].to);
            dfs(g[i].to, now, val + g[i].w);
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
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        addEdge(x, y, v);
        addEdge(y, x, v);
    }
    dfs(1, -1, 0);
    int maxd = 0, maxp;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxd)
            maxd = dis[i], maxp = i;
    }
    printf("end.\n");
    memset(vis, 0, sizeof(vis));
    dfs(maxp, -1, 0);
    maxd = 0;
    int maxp2;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxd)
            maxd = dis[i], maxp2 = i;
    }
    printf("%d %d", maxp, maxp2);
}