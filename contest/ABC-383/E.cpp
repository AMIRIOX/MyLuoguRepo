#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define int long long
constexpr int maxn = 2e5 + 10;
int n, m, k, tot, fa[maxn];
int a[maxn], b[maxn];

struct edge {
    int u, v, w;
    edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge &b) { return this->w < b.w; }
} g[maxn];

int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

void unite(int uex, int uey) {
    fa[uex] = uey;
    a[uey] += a[uex];
    b[uey] += b[uex];
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        fa[i] = i;

    for (int i = 1; i <= m; i++) {
        int tu, tv, tw;
        cin >> tu >> tv >> tw;
        g[++tot] = edge(tu, tv, tw);
    }
    for (int i = 1; i <= k; i++) {
        int ta;
        cin >> ta;
        a[ta]++;
    }
    for (int i = 1; i <= k; i++) {
        int tb;
        cin >> tb;
        b[tb]++;
    }

    sort(g + 1, g + tot + 1);
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        int u = g[i].u, v = g[i].v;
        int uex = find(u), uey = find(v);
        if (uex == uey)
            continue;
        auto proc = [&](int _u, int _v) {
            if (a[_u] && b[_v]) {
                int com = min(a[_u], b[_v]);
                a[_u] -= com;
                b[_v] -= com;
                res += com * g[i].w;
            }
        };
        proc(uex, uey);
        proc(uey, uex);
    }
    cout << res << '\n';
    return 0;
}
