#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100010;
struct edge {
    int u, v, w;
} e[maxn];
int fa[maxn], ansv[maxn];
int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
int ans, n, m, tot;
void kruskal() {
    sort(e + 1, e + m + 1,
         [&](const edge& a, const edge& b) { return a.w < b.w; });
    for (int i = 1; i <= m; i++) {
        int uex = find(e[i].u), uey = find(e[i].v);
        if (uex == uey)
            continue;
        fa[uex] = uey;
        // ans += e[i].w;
        ansv[tot] = e[i].w;
        if (++tot == n - 1)
            break;
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    kruskal();
    for (int i = 0; i <= n - 1; i++) {
        ans = max(ans, ansv[i]);
    }
    printf("%d %d\n", n - 1, ans);
    return 0;
}