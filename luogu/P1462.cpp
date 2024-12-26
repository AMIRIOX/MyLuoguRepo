#include <climits>
#include <cstdio>
#include <iostream>
#include <queue>
#define int long long
using namespace std;
const int inf = LLONG_MAX / 3;  // 坑1：需要开long long的inf，我也不知道为什么。
const int limits = 1e11;
const int maxn = 1e4 + 10;
const int maxm = 5e5 + 10;
// 看到最大值的最小值想二分（注意二分对象 费用）
// 单调性：越大的最小值越可能合法
// 检查合法：剩下的条件有血量，血量和边绑定，跑最短路看能不能到
// 注意:检查过程中，由于题目要最小化点权而我们二分了，
// 所以不能经过点权超过我们二分出的最小值的点
int read() {
    int val = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        val = (val << 1) + (val << 3) + (c ^ 48);
        c = getchar();
    }
    return val * f;
}
struct edge {
    int to, w, nxt;
    edge() { nxt = -1; }
} Graph[maxm];
int tot, head[maxn];
void addEdge(int u, int to, int w) {
    tot++;
    Graph[tot].to = to;
    Graph[tot].w = w;
    Graph[tot].nxt = head[u];
    head[u] = tot;
}
struct node {
    int pos, val;
    node(int _pos, int _val) : pos(_pos), val(_val) {}
    bool operator<(const node& o) const { return this->val > o.val; }
};
int dis[maxn], f[maxn];
int n, m, b;
bool vis[maxn];
priority_queue<node> q;
bool dijkstra(long long lim = inf) {
    // cout << lim << endl;
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
        vis[i] = false;
    }
    dis[1] = 0;
    while (!q.empty())
        q.pop();
    if (f[1] > lim) {
        return false;
    }
    q.push(node(1, 0));
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        if (vis[x.pos])
            continue;
        vis[x.pos] = true;
        for (register int i = head[x.pos]; ~i; i = Graph[i].nxt) {
            int y = Graph[i].to;
            int val = Graph[i].w;
            if ((dis[y] > dis[x.pos] + val) && f[y] <= lim) {
                dis[y] = dis[x.pos] + val;
                if (!vis[y])
                    q.push(node(y, dis[y]));
            }
        }
    }
    return dis[n] <= b;
}
signed main() {
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        // scanf("%d", &f[i]);
        f[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        // scanf("%d %d %d", &x, &y, &w);
        x = read();
        y = read();
        w = read();
        addEdge(x, y, w);
        addEdge(y, x, w);
    }
    if (!dijkstra()) {
        printf("AFK\n");
        return 0;
    }
    // 二分最小值 单调性：最小值越大越可能合法
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        if (dijkstra(mid))
            r = mid;
        else
            l = mid + 1;
    } 
    if (dijkstra(l))            // 坑2 还要检查下l是否符合条件，上面检查inf只是初步排除。
        printf("%d\n", l);
    else
        printf("AFK\n");
    return 0;
}
