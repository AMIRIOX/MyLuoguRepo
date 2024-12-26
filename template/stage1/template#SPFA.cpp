// #include <bits/stdc++.h>
// using namespace std;
// int n, m, s;
// const int maxn = 5e5 + 10;
// struct edge
// {
//     int to, w, nxt;
// } g[maxn];
// int tot, head[maxn];
// void addEdge(int u, int to, int w)
// {
//     g[++tot].to = to;
//     g[tot].w = w;
//     // >=.=.=.=.=.=.=.=.=.=.=.=.=.=.=
//     g[tot].nxt = head[u];
//     head[u] = tot;
// }
// int dis[maxn], inq[maxn];
// void SPFA()
// {
//     memset(dis, 0x3f, sizeof(dis));
//     dis[s] = 0;
//     queue<int> q;
//     q.push(s);
//     inq[s] = true;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         inq[u] = false;
//         for (int i = head[u]; i; i = g[i].nxt)
//         {
//             int v = g[i].to;
//             if (dis[v] > dis[u] + g[i].w)
//             {
//                 dis[v] = dis[u] + g[i].w;
//                 if (!inq[v])
//                     q.push(v), inq[v] = true;
//             }
//         }
//     }
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
//     SPFA();
//     for (int i = 1; i <= n; i++)
//     {
//         printf("%d ", dis[i]==0x3f3f3f3f?0x7fffffff:dis[i]);
//     }
//     return 0;
// }

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