#ifdef BELLMAN_FORD
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// using namespace std;
// const int maxn = 2e5 + 10;
// struct edge {
//     int u, v, w;
// }e[maxn];
// int dis[maxn];
// bool bellman_ford(int n, int tot) {
//     memset(dis, 0x3f, sizeof(dis));
//     dis[1] = 0;
//     for (int i = 1; i < n /*i<=n-1*/; i++) {
//         for (int c = 1; c <= tot; c++) {
//             int u = e[c].u, v = e[c].v, w = e[c].w;
//             if (dis[u] < 0x3f3f3f3f && dis[v] > dis[u] + w) {
//                 dis[v] = dis[u] + w;
//             }
//         }
//     }
//     for (int c = 1; c <= tot; c++) {
//         int u = e[c].u, v = e[c].v, w = e[c].w;
//         if(dis[u]>=0x3f3f3f3f) continue;
//         if (dis[v] > dis[u] + w)
//             return true;
//     }
//     return false;
// }
// int main() {
//     int t;
//     int n, m;
//     scanf("%d", &t);
//     while (t--) {
//         int tot = 0;
//         scanf("%d %d", &n, &m);
//         for (int i = 1; i <= m; i++) {
//             int u, v, w;
//             scanf("%d %d %d", &u, &v, &w);
//             if (w >= 0) {
//                 e[++tot].u = u;
//                 e[tot].v = v;
//                 e[tot].w = w;
//                 e[++tot].u = v;
//                 e[tot].v = u;
//                 e[tot].w = w;
//             } else {
//                 e[++tot].u = u;
//                 e[tot].v = v;
//                 e[tot].w = w;
//             }
//         }
//         bool haveFH = bellman_ford(n, tot);
//         printf("%s\n", haveFH ? "YES" : "NO");
//     }
//     return 0;
// }
#endif

#include <cstdio>
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
int inq[maxn], dis[maxn];
int cnt[maxn];
int n, m;

bool SPFA() {
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push(1);
    inq[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = head[u]; i; i = g[i].nxt) {
            int v = g[i].to, w = g[i].w;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                    return true;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        memset(head,0,sizeof(head));
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (w >= 0) {
                add(u, v, w);
                add(v, u, w);
            } else {
                add(u, v, w);
            }
        }
        bool haveFH = SPFA();
        printf("%s\n", haveFH ? "YES" : "NO");
    }

    return 0;
}