#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
struct edge{
    int to, w, nxt;
    edge() { nxt = -1; }
} g[maxn];

int tot, head[maxn];
void add_edge(int u, int v, int w) {
    ++tot;
    g[tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

struct node {
    int pos, dis; //, stat;
    node(int _pos = 0, int _dis = 0/*, _stat = 0*/): pos(_pos), dis(_dis)/*, stat(_stat)*/ {}
    bool operator<(const node& b) const { return this->dis > b.dis; }
};

priority_queue<node> q;
int dis[maxn], path[maxn];
int n, m, s, t, h;
bool hr[maxn], vis[maxn];

void init() {
    s = 1, t = n, tot = 0;
    for(int i = 1; i <= n; ++i) { head[i] = -1; path[i] = -1; }
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(hr, 0, sizeof hr);
    priority_queue<node> empty;
    swap(empty, q);
}

void dijkstra() {
    q.push(node(s, 0/*, hr[s]*/));
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.top().pos; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; ~i; i = g[i].nxt) {
            int v = g[i].to, dt = g[i].w;
            // if(stat) dt /= 2;
            if(dis[v] > dis[u] + dt) {
                dis[v] = dis[u] + dt;
                if(!vis[v]) q.push(node(v, dis[v] /*, max(stat, hr[v])*/));
                path[v] = u;
            }
        }
    }
}

void print() {
    stack<int> ans;
    int p = path[t];
    while(~p) {
        ans.push(p);
        p = path[p];
    }
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << t << endl;
}

void solve() {
    cin >> n >> m >> h;
    init();
    for(int i = 1; i <= h; ++i) {
        int tmp; cin >> tmp;
        hr[tmp] = 1;
    }
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dijkstra();
    if(dis[t] != 0x3f3f3f3f) print();
    else cout << -1 << endl;
}

signed main() {
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}

