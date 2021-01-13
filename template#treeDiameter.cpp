#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
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
int bfs(int s)
{
    queue<int> q;
    while (!q.empty())
        q.pop();

    q.push(s);
    int maxnum = s, maxd = 0;
    memset(dis, 0, sizeof dis);
    memset(vis, 0, sizeof vis);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int i = head[u]; ~i; i = g[i].nxt)
        {
            if (vis[g[i].to])
                continue;
            vis[g[i].to] = true;
            dis[g[i].to] = max(dis[g[i].to], dis[u] + g[i].w);
            if (dis[g[i].to] > maxd)
                maxd = dis[g[i].to], maxnum = g[i].to;
            q.push(g[i].to);
        }
    }
    return maxnum;
}
int main()
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
    printf("input ok.\n");
    int left = bfs(1);
    int right = bfs(left);
    printf("%d %d", left, right);
    return 0;
}