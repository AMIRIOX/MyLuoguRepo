#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
//#define int long long
struct edge {
    int to, w, nxt;
    edge() { nxt = -1; }
}g[maxn];
int tot, head[maxn];
void addEdge(int u, int v, int w) {
    tot++;
    g[tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

int n, m, s, t;
int dis[maxn], vis[maxn];
struct node {
    int pos, dis;
    node(int _pos, int _dis): pos(_pos), dis(_dis) {}
    bool operator<(const node& o) const {
        return this->dis > o.dis;
    }
};
priority_queue<node> q;
void dijkstra() {
    dis[s] = 0;
    q.push(node(s, 0));
    while(!q.empty()) {
        int u = q.top().pos; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; ~i; i = g[i].nxt) {
            int v = g[i].to;
            if(dis[v] > dis[u] + g[i].w) {
                dis[v] = dis[u] + g[i].w;
                if(!vis[v]) q.push(node(v, dis[v]));
            }
        }
    }
}
signed main() {
    
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 1; i <= n; i++) head[i] = -1;
    for(int i = 1; i <= n; i++) dis[i] = 0x7fffffff;
    for(int i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        addEdge(x, y, w);
        addEdge(y, x, w);
    }
    dijkstra();
    printf("%d\n", dis[t]);
    return 0; 
}
