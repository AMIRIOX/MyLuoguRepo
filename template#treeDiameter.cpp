#include <cstdio>
#include <cstring>
#include <queue>
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
int dis[maxn];
bool vis[maxn];
int bfs(int s)
{
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    int maxd = 0, maxp;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int i = head[u]; ~i; i = g[i].nxt)
        {
            int v = g[i].to;
            if (vis[v])
                continue;
            vis[v] = true;
            dis[v] = dis[u] + g[i].w;
            if (dis[v] > maxd)
                maxd = dis[v], maxp = v;
            q.push(v);
        }
    }
    return maxp;
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
    int left = bfs(1);
    int right = bfs(left);
    printf("%d %d", left, right);
}