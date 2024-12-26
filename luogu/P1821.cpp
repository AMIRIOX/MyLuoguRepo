#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 2e5 + 10;
struct edge {
    int to, w, nxt;
} g[maxn];
int tot, head[maxn];
void add(int u, int to, int w) {
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
struct node {
    int u, dis;
    node(int _u, int _dis) : u(_u), dis(_dis) {}
    bool operator<(const node& o) const { return dis > o.dis; }
};
int dis[maxn], vis[maxn];
void dijkstra(int s) {
    priority_queue<node> q;
    q.push(node(s, 0));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        if (vis[x.u])
            continue;
        vis[x.u] = 1;
        for (int i = head[x.u]; i; i = g[i].nxt) {
            int v = g[i].to;
            if (dis[v] > dis[x.u] + g[i].w) {
                dis[v] = dis[x.u] + g[i].w;
                if (!vis[v])
                    q.push(node(v, dis[v]));
            }
        }
    }
}
int mdis[maxn];
int main() {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        add(x, y, v);
        add(y + n, x + n, v);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        mdis[i] = dis[i];
    dijkstra(s + n);
    for (int i = 1 + n; i <= n + n; i++) {
        mdis[i - n] += dis[i];
    }
    int ans = -0x7fffffff;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, mdis[i]);
    }
    printf("%d", ans);
    return 0;
}