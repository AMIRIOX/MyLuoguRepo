#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Seg {
    int l, r;
    bool operator<(const Seg &b) const {
        if (this->l != b.l)
            return this->l < b.l;
        else
            return this->r < b.r;
    }
};
void solve() {
    signed n;
    cin >> n;
    vector<Seg> seg(n);
    for (signed i = 0; i < n; i++) {
        cin >> seg[i].l >> seg[i].r;
    }

    vector<ll> ans(n, 0);
    for (int k = 0; k < 2; k++) {
        vector<signed> ord(n);
        iota(ord.begin(), ord.end(), 0);

        sort(ord.begin(), ord.end(), [&](signed i, signed j) {
            // 保证计算到 seg[i] 的贡献时, seg[i] 的 predictor 一定已经计算完了.
            if (seg[i].l != seg[j].l)
                return seg[i].l < seg[j].l;
            else
                return seg[i].r > seg[j].r;
        });


        set<int> sr;
        for (int i = 0; i < n; i++) {
            auto it = sr.lower_bound(seg[ord[i]].r);
            if (it != sr.end())
                ans[ord[i]] += *it - seg[ord[i]].r;
            sr.insert(seg[ord[i]].r);
        }

        // 沿原点翻转计算左半侧
        for(int i = 0; i < n; i++) {
            seg[i].l = -seg[i].l;
            seg[i].r = -seg[i].r;
            swap(seg[i].l, seg[i].r);
        }
    }

    // 去重
    map<Seg, int> cnt;
    for(auto s : seg) cnt[s]++;
    for(int i = 0; i < n; i++)
        cout << (cnt[seg[i]] > 1 ? 0 : ans[i]) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
