#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 10;
struct edge {
    int u, v, w;
}e[maxn];
int dis[maxn];
bool bellman_ford(int n, int tot) {
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i < n /*i<=n-1*/; i++) {
        for (int c = 1; c <= tot; c++) {
            int u = e[c].u, v = e[c].v, w = e[c].w;
            if (dis[u] < 0x3f3f3f3f && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }
    for (int c = 1; c <= tot; c++) {
        int u = e[c].u, v = e[c].v, w = e[c].w;
        if(dis[u]>=0x3f3f3f3f) continue;
        if (dis[v] > dis[u] + w)
            return true;
    }
    return false;
}
int main() {
    int t;
    int n, m;
    scanf("%d", &t);
    while (t--) {
        int tot = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (w >= 0) {
                e[++tot].u = u;
                e[tot].v = v;
                e[tot].w = w;
                e[++tot].u = v;
                e[tot].v = u;
                e[tot].w = w;
            } else {
                e[++tot].u = u;
                e[tot].v = v;
                e[tot].w = w;
            }
        }
        bool haveFH = bellman_ford(n, tot);
        printf("%s\n", haveFH ? "YES" : "NO");
    }
    return 0;
}
