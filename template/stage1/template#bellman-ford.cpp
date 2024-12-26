// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 1e8+10;
// int n, m, s;
// struct edge
// {
//     int self, to, w, nxt;
// } g[maxn];
// int tot, head[maxn];
// void addEdge(int u, int to, int w)
// {
//     g[++tot].to = to;
//     g[tot].self = u;
//     g[tot].w = w;
//     g[tot].nxt = head[u];
//     head[u] = tot;
// }
// int dis[maxn];
// bool bellman_ford()
// {
//     memset(dis, 0x3f, sizeof(dis));
//     dis[s] = 0;
//     for (int i = 1; i < n; i++)
//     {
//         for (int cnt = 1; cnt <= tot; cnt++)
//         {
//             if (dis[g[cnt].to] > dis[g[cnt].self] + g[cnt].w)
//             {
//                 dis[g[cnt].to] = dis[g[cnt].self] + g[cnt].w;
//             }
//         }
//     }
//     for (int i = 1; i <= tot; i++)
//     {
//         if (dis[g[i].to] > dis[g[i].self] + g[i].w)
//             return true;
//     }
//     return false; //TODO
// }
// int main()
// {
//     scanf("%d %d %d", &n, &m, &s);
//     for (int i = 1; i <= m; i++)
//     {
//         int x, y, v;
//         scanf("%d %d %d", &x, &y, &v);
//         addEdge(x, y, v);
//     }
//     if(bellman_ford()) printf("YES\n");
//     for (int i = 1; i <= n; i++)
//     {
//         printf("%d ", dis[i] == 0x3f3f3f3f ? 0x7fffffff : dis[i]);
//     }
//     return 0;
// }

#ifdef BELLMAN_FORD_METHOD
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
#endif

