#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 100010*2;

struct edge
{
    int to;
    double w; 
    int nxt;
    edge() { nxt = 0; }
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, double w)
{
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

int vis[maxn];
double dis[maxn];
struct node
{
    int u;
    double dis;
    node(int _u, double _dis) : u(_u), dis(_dis) {}
    bool operator<(const node &o) const
    {
        return this->dis < o.dis;
    }
};

void dijkstra(int s)
{
    priority_queue<node> q;
    q.push(node(s, 1.0));
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 1.0;
    while (!q.empty())
    {
        node u = q.top();
        q.pop();
        if (vis[u.u])
            continue;
        vis[u.u] = 1;
        for (int i = head[u.u]; i; i = g[i].nxt)
        {
            int y = g[i].to;
            if (dis[y] < dis[u.u] * g[i].w)
                dis[y] = dis[u.u] * g[i].w;
            if (!vis[y])
                q.push(node(y, dis[y]));
        }
    }
}
int main(void)
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        double v;
        scanf("%d %d %lf", &x, &y, &v);
        v = 1.0 - ((double)v) / 100.0;
        addEdge(x, y, v);
        addEdge(y, x, v);
    }
    scanf("%d %d", &a, &b);
    dijkstra(a);
    // cout << dis[b] << endl;
    printf("%.8lf", 100.0 / dis[b]);
    return 0;
}