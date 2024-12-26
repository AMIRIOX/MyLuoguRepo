#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
struct edge {
    int x, y, v;
} e[maxn];
int fa[maxn];
int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
int n, m, s, t;
int tot;
int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v);
    }

    sort(e + 1, e + m + 1,
         [&](const edge& a, const edge& b) { return a.v < b.v; });
    for (int i = 1; i <= m; i++) {
        int uex = find(e[i].x), uey = find(e[i].y);
        if (uex == uey)
            continue;
        fa[uex] = uey;
        if (find(s) == find(t)) {
            printf("%d\n", e[i].v);
            return 0;
        }
        if (++tot == n - 1)
            break;
    }

    return 0;
}