#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    ll ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        if(a[i] == '.' && a[i - 1] != 'x' && a[i + 1] != 'x' && b[i] == '.' && b[i - 1] == 'x' && b[i + 1] == 'x') ans++;
    }
    for (int i = 1; i + 1 < n; i++) {
        if(b[i] == '.' && b[i - 1] != 'x' && b[i + 1] != 'x' && a[i] == '.' && a[i - 1] == 'x' && a[i + 1] == 'x') ans++;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
