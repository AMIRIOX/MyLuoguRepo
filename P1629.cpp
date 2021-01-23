#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e6 + 10;
struct edge {
    int to, w, nxt;
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w) {
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int dis[maxn], vis[maxn];
struct node {
    int u, dis;
    node(int _u, int _dis) : u(_u), dis(_dis) {}
    bool operator<(const node& o) const { return dis > o.dis; }
};
void dijkstra(int s) {
    priority_queue<node> q;
    q.push(node(s, 0));
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    while (!q.empty()) {
        node u = q.top();
        q.pop();
        int ui = u.u;
        if (vis[ui])
            continue;
        vis[ui] = 1;
        if (dis[ui] < u.dis)
            continue;
        for (int i = head[ui]; i; i = g[i].nxt) {
            int v = g[i].to;
            if (dis[v] > dis[ui] + g[i].w)
                dis[v] = dis[ui] + g[i].w;
            if (!vis[v])
                q.push(node(v, dis[v]));
        }
    }
}
int n, m;
int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; ++i) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        addEdge(x, y, v);
        addEdge(y + n, x + n, v);
    }
    long long ans = 0;
    dijkstra(1);
    for (int i = 2; i <= n; ++i) {
        ans += dis[i];
    }
    dijkstra(1 + n);
    for (int i = 2 + n; i <= n << 1; ++i) {
        ans += dis[i];  
    }
    printf("%lld", ans);
    return 0;
}