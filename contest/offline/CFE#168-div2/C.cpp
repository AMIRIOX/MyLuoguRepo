#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; string s;
    cin >> n >> s;
    assert(n % 2 == 0);
    ll ans = 0;
    for(int i = 0; i + 1 < n; i += 2) {
        if(s[i + 1] == ')') {
            ans++;
        }else {
            int lst = i;
            for(i = i + 2; i + 1 < n && s[i + 1] != ')'; i += 2) ans++; 
            ans++;
            ans += (i + 1 - lst);
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
