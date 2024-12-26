#include <iostream>
using namespace std;
const int maxn = 2e5 + 10;
int read() {
    int val = 0, flg = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flg = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        val = (val << 3) + (val << 1) + (ch ^ 48);
        ch = getchar();
    }
    return val * flg;
}
struct edge {
    int to, w, nxt;
} g[maxn << 1];
int tot, head[maxn], n, m;
inline void add(int u, int to, int w) {
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int dis[maxn], now = 1, cntn, vis[maxn];
int ans;
inline int prim() {
    for (register int i = 2; i <= n; i++) {
        dis[i] = 0x7fffffff;
    }
    for (register int i = head[now]; i; i = g[i].nxt) {
        dis[g[i].to] = min(dis[g[i].to], g[i].w);
    }
    while (++cntn < n) {
        int minx = 0x7fffffff;
        vis[now] = 1;
        for (register int i = 1; i <= n; i++) {
            if (!vis[i] && minx > dis[i]) {
                minx = dis[i];
                now = i;
            }
        }
        ans += minx;
        for (register int i = head[now]; i; i = g[i].nxt) {
            int v = g[i].to;
            if (dis[v] > g[i].w && !vis[v])
                dis[v] = g[i].w;
        }
    }
    return ans;
}
int main() {
    // scanf("%d %d", &n, &m);
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        // scanf("%d %d %d", &x, &y, &v);
        x = read(), y = read(), v = read();
        add(x, y, v);
        add(y, x, v);
    }
    printf("%d", prim());
    return 0;
}