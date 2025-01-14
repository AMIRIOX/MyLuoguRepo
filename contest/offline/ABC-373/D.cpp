#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 4e5 + 10;

int n, m;
struct edge {
    int to, nxt;
    ll w;
};
int tot;
vector<edge> g(maxn);
vector<int> head(maxn, -1);
void add_edge(int u, int v, ll w) {
    ++tot;
    g[tot].to = v;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}

vector<short> vis(maxn, 0);
vector<ll> ans(maxn, 2e16);
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = g[i].nxt) {
        int v = g[i].to;
        ll w = g[i].w;
        ans[v] = ans[u] + w;
        dfs(v);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, -w);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans[i] = 0;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
