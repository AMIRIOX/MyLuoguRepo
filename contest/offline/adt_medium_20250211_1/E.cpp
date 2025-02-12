#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    while(q--) {
        int x; cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        if(it == end(a)) cout << 0 << '\n';
        else cout << a.end() - it << '\n';
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

