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
struct node {
    int u, dis;
    node(int _u, int _dis) : u(_u), dis(_dis) {}
    bool operator<(const node& o) const { return dis > o.dis; }
};
int dis[maxn], vis[maxn];
void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> q;
    q.push(node(s, 0));
    dis[s] = 0;
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        if (vis[x.u])
            continue;
        vis[x.u] = 1;
        for (int i = head[x.u]; i; i = g[i].nxt) {
            int v = g[i].to;
            if (dis[v] > dis[x.u] + g[i].w) {
                dis[v] = dis[x.u] + g[i].w;
                if (!vis[v])
                    q.push(node(v, dis[v]));
            }
        }
    }
}
int main() {
    int n, s, e;
    scanf("%d %d %d", &n, &s, &e);
    for (int i = 1; i <= n; i++) {
        int nums;
        scanf("%d", &nums);
        for (int j = 1; j <= nums; j++) {
            int y;
            scanf("%d", &y);
            add(i, y, j == 1 ? 0 : 1);
        }
    }
    dijkstra(s);
    printf("%d", dis[e] == 0x3f3f3f3f ? -1 : dis[e]);
    return 0;
}