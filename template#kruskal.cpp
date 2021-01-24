#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxm = 2e5 + 10;
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
    int x, y, v;
} g[maxm];
bool cmp(const edge& a, const edge& b) {
    return a.v < b.v;
}
int n, m, ans, tot, fa[maxm];
int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
inline void kruskal() {
    sort(g + 1, g + m + 1,
         [&](const edge& a, const edge& b) { return a.v < b.v; });
    for (register int i = 1; i <= m; ++i) {
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
    n = read(), m = read();
    for (register int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (register int i = 1; i <= m; ++i) {
        g[i].x = read();
        g[i].y = read();
        g[i].v = read();
    }
    kruskal();
    printf("%d", ans);
    return 0;
}