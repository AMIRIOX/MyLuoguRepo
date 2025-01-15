#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    if(s == t) {
        cout << 0 << '\n';
        return;
    }
    for(size_t i = 0; i < min(s.size(), t.size()); i++) {
        if(s[i] != t[i]) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << min(s.size(), t.size()) + 1 << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

