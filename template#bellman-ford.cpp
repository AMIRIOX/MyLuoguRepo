#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8+10;
int n, m, s;
struct edge
{
    int self, to, w, nxt;
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w)
{
    g[++tot].to = to;
    g[tot].self = u;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int dis[maxn];
bool bellman_ford()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int cnt = 1; cnt <= tot; cnt++)
        {
            if (dis[g[cnt].to] > dis[g[cnt].self] + g[cnt].w)
            {
                dis[g[cnt].to] = dis[g[cnt].self] + g[cnt].w;
            }
        }
    }
    for (int i = 1; i <= tot; i++)
    {
        if (dis[g[i].to] > dis[g[i].self] + g[i].w)
            return true;
    }
    return false; //TODO
}
int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        addEdge(x, y, v);
    }
    bellman_ford();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dis[i] == 0x3f3f3f3f ? 0x7fffffff : dis[i]);
    }
    return 0;
}