#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    ll cnt = 0;
    for(size_t i = 1; i <= 12; i++) {
        cin >> s;
        if(s.length() == i) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

