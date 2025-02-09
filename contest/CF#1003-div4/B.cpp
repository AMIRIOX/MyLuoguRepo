#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    bool ok = false;
    for(size_t i = 1; i < s.length(); i++) {
        if(s[i] == s[i - 1]) ok = true;
    }
    if(ok) cout << 1 << '\n';
    else cout << s.length() << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
