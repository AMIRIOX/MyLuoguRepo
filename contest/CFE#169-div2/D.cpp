#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using std::views::filter;

bool has_same(const string &a, const string &b) {
    if (a[0] == b[0] || a[0] == b[1])
        return true;
    if (a[1] == b[0] || a[1] == b[1])
        return true;
    return false;
}

void solve() {
    int n = 0, q = 0;
    cin >> n >> q;
    vector<string> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        if (in[i][0] > in[i][1])
            swap(in[i][0], in[i][1]);
    }
    const vector<string> type = {"BG", "BR", "BY", "GR", "GY", "RY"};
    map<string, int> m;
    vector<int> lc(n, -1), rc(n, -1);

    for (int i = 0; i < n; i++) {
        auto condi =
            m | filter([&](const auto &p) { return p.first != in[i] && has_same(p.first, in[i]); });
        if (auto lci = ranges::max_element(
                condi, [](const auto &a, const auto &b) { return a.second < b.second; });
            lci != ranges::end(condi)) {
            lc[i] = lci->second;
        }
        m[in[i]] = i;
    }
    m.clear();
    for (int i = n - 1; i >= 0; i--) {
        auto condi =
            m | filter([&](const auto &p) { return p.first != in[i] && has_same(p.first, in[i]); });
        if (auto rci = ranges::min_element(
                condi, [](const auto &a, const auto &b) { return a.second < b.second; });
            rci != ranges::end(condi))
            rc[i] = rci->second;
        m[in[i]] = i;
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y)
            swap(x, y);
        if (has_same(in[x], in[y])) {
            cout << abs(x - y) << '\n';
            continue;
        }

        int ans = 0x7fffffff;
        if (~lc[x])
            ans = min(abs(lc[x] - x) + abs(lc[x] - y), ans);
        if (~rc[x])
            ans = min(abs(rc[x] - x) + abs(rc[x] - y), ans);
        cout << (ans == 0x7fffffff ? -1 : ans) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
