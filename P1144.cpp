#define MOD 100003
#ifdef SPFA_METHOD

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
// #define int long long
using namespace std;
const int maxn = 2e7 + 10;
struct edge {
    int to, nxt;
} g[maxn];
int tot, head[maxn];
void add(int u, int to) {
    g[++tot].to = to;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int n, m;
int dis[maxn], inq[maxn];
int ans[maxn];
void SPFA() {
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;
    ans[1] = 1;
    queue<int> q;
    q.push(1);
    inq[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = head[u]; i; i = g[i].nxt) {
            int v = g[i].to;
            if (dis[v] > dis[u] + 1) {
                ans[v] = ans[u];
                // ans[v] %= 100003;

                dis[v] = dis[u] + 1;
                if (!inq[v])
                    q.push(v), inq[v] = 1;
            } else if (dis[v] == dis[u] + 1) {
                ans[v] += ans[u];
                ans[v] %= 100003;
            }
        }
    }
}
signed main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x != y) {
            add(x, y);
            add(y, x);
        }
    }
    SPFA();
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
#endif

#ifdef BFS_METHOD
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
// #define int long long
using namespace std;
const int maxn = 2e7 + 10;
struct edge {
    int to, nxt;
} g[maxn];
int tot, head[maxn];
void add(int u, int to) {
    g[++tot].to = to;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int n, m;
int dep[maxn], vis[maxn], ans[maxn];
void bfs() {
    dep[1] = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    ans[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = g[i].nxt) {
            int v = g[i].to;
            if (!vis[v]) {
                dep[v] = dep[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
            if (dep[v] == dep[u] + 1)
                ans[v] = (ans[v] + ans[u]) % MOD;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x != y) {
            add(x, y);
            add(y, x);
        }
    }
    bfs();
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}
#endif