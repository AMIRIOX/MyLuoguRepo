#include <bits/stdc++.h>
using namespace std;
int n, m, s;
const int maxn = 5e5 + 10;
struct edge
{
    int to, w, nxt;
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w)
{
    g[++tot].to = to;
    g[tot].w = w;
    // >=.=.=.=.=.=.=.=.=.=.=.=.=.=.=
    g[tot].nxt = head[u];
    head[u] = tot;
}
int dis[maxn], inq[maxn];
void SPFA()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    inq[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = head[u]; i; i = g[i].nxt)
        {
            int v = g[i].to;
            if (dis[v] > dis[u] + g[i].w)
            {
                dis[v] = dis[u] + g[i].w;
                if (!inq[v])
                    q.push(v), inq[v] = true;
            }
        }
    }
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
    SPFA();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dis[i]==0x3f3f3f3f?0x7fffffff:dis[i]);
    }
    return 0;
}