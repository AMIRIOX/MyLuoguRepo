#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
constexpr ll maxn = 5e5 + 10;
constexpr ll inf = 2e18;
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
    ll pos, dis;
    bool stat;
    node(ll _pos, ll _dis, bool _stat = false) : 
        pos(_pos), dis(_dis), stat(_stat) {}
    bool operator<(const node& b) const { 
        return this->dis > b.dis; 
    }
};

ll n, m, s, t, h;

void init() {
    tot = 0;
    memset(head, -1, sizeof head);
}

void dijkstra(answer& dis, vector<bool>& hr) {
    priority_queue<node> q;
    q.push(node(s, 0, hr[s]));
    dis[s][hr[s]] = 0;
    while(!q.empty()) {
        ll u = q.top().pos, statu = q.top().stat; q.pop();
        for(ll i = head[u]; ~i; i = g[i].nxt) {
            ll v = g[i].to, dt = g[i].w;
            ll statv = (statu || hr[v]);
            if(statu) dt >>= 1;
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

    vector<bool> hr(n + 1);
    for(ll i = 1; i <= h; ++i) {
        hr[read()] = 1;
    }

    ll u, v, w;
    for(ll i = 1; i <= m; ++i) {
        u = read(); v = read(); w = read();
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    answer dis1(n + 1, vector<ll>(2, inf));
    answer dis2(n + 1, vector<ll>(2, inf));

    s = 1, t = n;
    dijkstra(dis1, hr);

    s = n, t = 1;
    dijkstra(dis2, hr);

    ll ans = inf;
    for(ll i = 1; i <= n; ++i) {
        ans = min(ans, max(min(dis1[i][0], dis1[i][1]), min(dis2[i][0], dis2[i][1])));
    }
    printf("%lld\n", (ans == inf ? -1 : ans));
}

signed main() {
    int T = (int)read();
    while(T--) solve();
    return 0;
}
