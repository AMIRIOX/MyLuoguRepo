#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
struct edge {
    int to, nxt;
} g[maxn << 1];
int tot, head[maxn];
void add(int u, int to) {
    g[++tot].to = to;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int logs[maxn];
void logo() {
    logs[1] = 0;
    logs[2] = 1;
    for (int i = 3; i <= maxn; i++) {
        logs[i] = logs[i / 2] + 1;
    }
}
int depth[maxn], fa[maxn][22];
void dfs(int now, int fath) {
    // 计算深度，以及每个点向上跳2^x能到的祖父节点
    fa[now][0] = fath;
    depth[now] = depth[fath] + 1;

    for (int i = 1; i <= logs[depth[now]]; i++)
        fa[now][i] = fa[fa[now][i - 1]][i - 1];

    for (int i = head[now]; i; i = g[i].nxt) {
        if (g[i].to != fath)
            dfs(g[i].to, now);
    }
}
int LCA(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    while (depth[x] > depth[y])
        x = fa[x][logs[depth[x] - depth[y]]];
    if (x == y)
        return x;
    for (int k = logs[depth[x]]; k >= 0; k--) {
        if (fa[x][k] != fa[y][k])
            x = fa[x][k], y = fa[y][k];
    }
    return fa[x][0];
}
int n, y, s, m;
int main() {
    scanf("%d %d %d", &n, &y, &s);
    m = n - 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        add(x, y);
        add(y, x);
    }
    logo();
    dfs(s, 0);
    for (int i = 1; i <= y; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", LCA(x, y));
    }
    return 0;
}