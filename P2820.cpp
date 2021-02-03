#include <cstdio>
#include <cstring>
#include <iostream>
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
int vis[maxn], dis[maxn], cnt;
int n, m, now = 1;
int prim() {
    int ans = 0;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i = head[now]; i; i = g[i].nxt) {
        dis[g[i].to] = min(dis[g[i].to], g[i].w);
    }
    while (++cnt < n) {
        int minx = 0x3f3f3f3f;
        vis[now] = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dis[i] < minx) {
                minx = dis[i];
                now = i;
            }
        }
        ans += minx;
        for (int i = head[now]; i; i = g[i].nxt) {
            int v = g[i].to;
            if (dis[v] > g[i].w && !vis[v]) {
                dis[v] = g[i].w;
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d %d", &n, &m);
    int maxe = 0;
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        if (v != 0) {
            add(x, y, v);
            add(y, x, v);
            maxe += v;
        }
    }
    printf("%d\n", maxe - prim());
    return 0;
}