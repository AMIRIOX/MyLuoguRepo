#ifdef KRUSKAL_METHOD
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxm = 2e5 + 10;
struct edge {
    int x, y, v;
} g[maxm];
int n, m, ans, tot, fa[maxm];
int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
void kruskal() {
    sort(g + 1, g + m + 1,
         [&](const edge& a, const edge& b) { return a.v < b.v; });
    for (register int i = 1; i <= m; i++) {
        int uex = find(g[i].x), uey = find(g[i].y);
        if (uex == uey)
            continue;
        ans += g[i].v;
        fa[uex] = uey;
        if (++tot == n - 1)
            break;
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        g[i].x = x;
        g[i].y = y;
        g[i].v = v;
    }
    kruskal();
    printf("%d", ans);
    return 0;
}
#endif



#ifdef PRIM_METHOD
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
#endif