#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
constexpr ll maxn = 4e5 + 10;
using answer = vector<vector<ll> >;

inline ll read() {
    ll val = 0, flg = 1;
    char ch = (char) getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') flg = 0;
        ch = (char) getchar();
    }
    while(ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char) getchar();
    }
    return flg ? val : ~(val - 1);
}

struct edge{
    ll to, w, nxt;
    edge() { nxt = -1; }
} g[maxn];

ll tot, head[maxn];
void add_edge(ll u, ll v, ll w) {
    ++tot;
    g[tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

struct node {
    ll pos, dis, stat;
    node(ll _pos, ll _dis, ll _stat = 0): pos(_pos), dis(_dis), stat(_stat) {}
    bool operator<(const node& b) const { return this->dis > b.dis; }
};

ll n, m, s, t, h;
ll hr[maxn], vis[maxn][2];

void init() {
    tot = 0;
    memset(head, -1, sizeof head);
    memset(hr, 0, sizeof hr);
    memset(vis, 0, sizeof vis);
}

void dijkstra(answer& dis) {
    priority_queue<node> q;
    q.push(node(s, 0, hr[s]));
    dis[s][hr[s]] = 0;
    while(!q.empty()) {
        ll u = q.top().pos, statu = q.top().stat; q.pop();
        for(ll i = head[u]; ~i; i = g[i].nxt) {
            ll v = g[i].to, dt = g[i].w;
            ll statv = max(statu, hr[v]);
            if(statu) dt /= 2;
            if(dis[v][statv] > dis[u][statu] + dt) {
                dis[v][statv] = dis[u][statu] + dt;
                q.push(node(v, dis[v][statv], statv));
            }
        }
    }
}


void solve() {
    n = read(); m = read(); h = read();
    init();
    for(ll i = 1; i <= h; ++i) {
        hr[read()] = 1;
    }
    ll u, v, w;
    for(ll i = 1; i <= m; ++i) {
        u = read(); v = read(); w = read();
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    answer dis1(n + 1, vector<ll>(2, 2e18));
    answer dis2(n + 1, vector<ll>(2, 2e18));

    s = 1, t = n;
    dijkstra(dis1);

    s = n, t = 1;
    dijkstra(dis2);

    long long ans = 2e18;
    for(ll i = 1; i <= n; ++i) {
        ans = min(ans, max(min(dis1[i][0], dis1[i][1]), min(dis2[i][0], dis2[i][1])));
    }
    cout << (ans == 2e18 ? -1 : ans) << endl;
}

signed main() {
    int t = read();
    while(t--) solve();
    return 0;
}
