#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    vector<int> len;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        len.push_back(s.length());
    }
    ll tot = 0, ans = 0;
    for(auto L: len) {
        if(tot + L <= m) {
            tot += L;
            ans++;
        }else break;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
