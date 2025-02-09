#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dsu {
  private:
    int n;

    // root: size * -1
    // others: parent
    vector<int> parent_or_size;

  public:
    vector<vector<array<int, 3>>> g;
    Dsu() : n(0) {}
    explicit Dsu(int _size) : n(_size), parent_or_size(n, -1), g(n) {}
    int leader(int x) {
        if (parent_or_size[x] < 0)
            return x;
        return parent_or_size[x] = leader(parent_or_size[x]);
    }
    int merge(int x, int y) {
        if ((x = leader(x)) == (y = leader(y)))
            return x;
        if (-parent_or_size[x] < -parent_or_size[y])
            swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        g[x].insert(g[x].end(), g[y].begin(), g[y].end());
        g[y].clear();
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    int size(int x) { return -parent_or_size[leader(x)]; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Dsu d(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (d.same(u, v)) {
            // useless
            d.g[d.leader(u)].push_back({u, v, i});
        } else {
            d.merge(u, v);
        }
    }

    vector<pair<int, int>> compo;
    for (int i = 0; i < n; i++)
        if (d.leader(i) == i)
            compo.push_back({d.g[i].size(), i});
    sort(compo.rbegin(), compo.rend());

    cout << compo.size() - 1 << '\n';

    int pos = 1;
    for (auto &[_, root] : compo) {
        for (auto &[x, _, idx] : d.g[root]) {
            if (pos < int(compo.size()))
                cout << idx + 1 << ' ' << x + 1 << ' ' << compo[pos++].second + 1 << '\n';
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
