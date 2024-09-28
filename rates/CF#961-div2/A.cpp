#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, k = 0;
    cin >> n >> k;
    if(!k) { cout << 0 << endl; return; }
    int ans = 1, dig = n - 1;
    if(k <= n) { cout << ans << endl; return; }
    k -= n;
    while(k > 0 && dig > 0) {
        if(k > dig) k -= dig, ans++;
        else { ans++; break; }
        if(k > dig) k -= dig, ans++;
        else { ans++; break; }
        dig--;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
