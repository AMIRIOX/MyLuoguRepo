#include <cstdio>
#include <iostream>
#include <queue>
// #define int long long
// #define INF 9223372036854775800LL
using namespace std;
const int maxn = 5e5 + 10;
struct edge {
    int to, w, nxt;
    edge() { nxt = -1; }
} g[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w) {
    tot++;
    g[tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
struct node {
    int pos, dis;
    node(int pos_, int dis_) : pos(pos_), dis(dis_) {}
    bool operator<(const node& o) const { return this->dis > o.dis; }
};
priority_queue<node> q;
int n, m, s, t;
int dis[maxn], book[maxn];
void dijkstra() {
    dis[s] = 0;
    q.push(node(s, 0));
    while (!q.empty()) {
        // while (!q.empty() && book[q.top().pos]) q.pop();
        node cur = q.top();
        q.pop();
        int u = cur.pos;
        if (book[u])
            continue;
        book[u] = 1;
        for (int i = head[u]; ~i; i = g[i].nxt) {
            if (dis[g[i].to] > dis[u] + g[i].w) {
                dis[g[i].to] = dis[u] + g[i].w;
                if (!book[g[i].to]) {
                    q.push(node(g[i].to, dis[g[i].to]));
                }
            }
        }
    }
}
signed main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    for (int i = 1; i <= n; i++)
        dis[i] = 0x7fffffff;
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        addEdge(x, y, v);
        addEdge(y, x, v);
    }
    dijkstra();
    // for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
    printf("%d", dis[t]);
    return 0;
}