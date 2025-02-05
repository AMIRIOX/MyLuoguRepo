#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct query {
    int i, idx;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<vector<query>> q(n + 1);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        q[tmp2].push_back({tmp1 - 1, i});
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] > a[j]; });

    for (int i = 0; i < n + 1; i++)
        sort(q[i].begin(), q[i].end(), [&](auto &a, auto &b) { return a.i > b.i; });

    vector<int> ans(m);
    vector<int> cur(n + 1, 0);

    ordered_set<int> escape_or_live{ord.begin(), ord.end()};
    for (int lvl = 1; lvl <= n; lvl++) {
        for (int k = 1; k <= n; k++) {
            if (cur[k] >= n)
                break;
            int x = escape_or_live.order_of_key(cur[k]);
            int pos = (x + k - 1 >= int(escape_or_live.size())
                           ? n
                           : *escape_or_live.find_by_order(x + k - 1));
            while (!q[k].empty() && q[k].back().i <= pos) {
                ans[q[k].back().idx] = (a[q[k].back().i] >= lvl);
                q[k].pop_back();
            }
            cur[k] = pos + 1;
        }
        while (!ord.empty() && a[ord.back()] == lvl) {
            escape_or_live.erase(ord.back());
            ord.pop_back();
        }
    }

    for (const auto &i : ans)
        cout << (i ? "YES" : "NO") << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
