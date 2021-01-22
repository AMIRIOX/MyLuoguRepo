#include <iostream>
#include <cmath>
#include <cstring>
#define int unsigned long long
const int maxn = 2e5 + 10;
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
int n, m;
int ans = pow(2, 63) - 1;
int min(int a, int b) { return a > b ? b : a; }
int vis[maxn];
bool allvis()
{
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            return false;
    }
    return true;
}
void dfs(int par, int u, int val)
{
    vis[u] = true;
    if (allvis())
        memset(vis, 0, sizeof(vis));
    if (u == 1 && par != -1)
    {
        //ans yes
        ans = min(ans, val);
        memset(vis, 0, sizeof(vis));
        return;
    }
    for (int i = head[u]; i; i = g[i].nxt)
    {
        if (!vis[g[i].to])
            dfs(u, g[i].to, val + g[i].w);
    }
}
signed main()
{
    int n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        scanf("%lld %lld %lld", &x, &y, &v);
        addEdge(x, y, v);
        addEdge(y, x, v);
    }
    std::cout << "input ok" << std::endl;
    dfs(-1, 1, 0);
    printf("%d", ans);
    return 0;
}