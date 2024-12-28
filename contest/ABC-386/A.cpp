#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<int> a(4);
    map<int, int> cnt;
    ll tot = 0;
    for (auto &i : a) {
        cin >> i;
        if (!cnt[i])
            tot++;
        cnt[i]++;
    }
    if(tot == 2) cout << "Yes\n";
    else cout << "No\n";
    // aaab b
    // aabb b
    // abbb a
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
