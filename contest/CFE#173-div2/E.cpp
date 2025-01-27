#include <bits/stdc++.h>
using namespace std;

struct Graph {
    vector<vector<signed>> edges;
    vector<signed> color;

    Graph(signed n) : edges(vector<vector<signed>>(n)), color(n, 0) {}

    void add_edge(signed i, signed j) { edges[i].push_back(j); }

    // color[u] == 0 : 完全未访问过的节点
    // color[u] == 1 : 访问过在栈中的节点
    // color[u] == 2 : 访问完已经出栈的节点
    bool dfs(signed u) {
        if (color[u] != 0)
            return false;
        color[u] = 1;
        bool res = false;
        for (auto v : edges[u]) {
            if (color[v] == 2)
                continue;
            else if (color[v] == 0)
                res |= dfs(v);
            else
                res = true;
        }
        color[u] = 2;
        return res;
    }
};

inline bool get_bit(signed n, short k) { return (n >> k) & 1; }

bool check(vector<vector<signed>> &a, vector<vector<signed>> &b, short bit) {
    const signed n = a.size();
    const signed m = a[0].size();
    vector<signed> must_row(n, 0);
    vector<signed> must_col(m, 0);
    Graph g(n + m);
    for (signed i = 0; i < n; i++) {
        for (signed j = 0; j < m; j++) {
            if (get_bit(a[i][j], bit) != get_bit(b[i][j], bit)) {
                if (get_bit(b[i][j], bit) == 0)
                    must_row[i] = 1;
                else
                    must_col[j] = 1;
            }
            if (get_bit(b[i][j], bit) == 0)
                g.add_edge(j + n, i);
            else
                g.add_edge(i, j + n);
        }
    }
    for (signed i = 0; i < n; i++) {
        if (must_row[i] && g.dfs(i))
            return false;
    }
    for (signed j = 0; j < m; j++) {
        if (must_col[j] && g.dfs(j + n))
            return false;
    }
    return true;
}

void solve() {
    signed n, m;
    cin >> n >> m;
    vector a(n, vector<signed>(m));
    vector b(n, vector<signed>(m));
    for (signed i = 0; i < n; i++)
        for (signed j = 0; j < m; j++)
            cin >> a[i][j];
    for (signed i = 0; i < n; i++)
        for (signed j = 0; j < m; j++)
            cin >> b[i][j];
    for (short bit = 0; bit < 30; bit++) {
        // 2**30 1e9; 3**31 INT_MAX 2e9
        if (!check(a, b, bit)) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
