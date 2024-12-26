#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>

void solve() {
    ll m, a, b, c;
    cin >> m >> a >> b >> c;
    ll u = min(a, m), v = min(b, m);
    ll rem = m + m - u - v;
    cout << u + v + min(rem, c) << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
