// 关闭流同步后不要混用 endl 和 '\n'
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    unordered_map<int, int> cnt;
    int ans = 0;
    for (auto &i : a) {
        cin >> i;
        cnt[i]++;
    }
    int ansl = -1, ansr = -1;
    bool into = false;
    int inl = 0, inr = 0;

    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 1) {
            tot++;
            if (into) {
                inr = i;
            } else {
                into = true;
                inl = inr = i;
            }
        } else {
            if (into) {
                into = false;
                if (tot > ans) {
                    ans = tot;
                    ansl = inl;
                    ansr = inr;
                }
                tot = 0;
            }
        }
    }
    if (into) {
        into = false;
        if (tot > ans) {
            ans = tot;
            ansl = inl;
            ansr = inr;
        }
        tot = 0;
    }

    if (~ansl && ~ansr)
        cout << ansl + 1 << ' ' << ansr + 1 << '\n';
    else
        cout << 0 << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
