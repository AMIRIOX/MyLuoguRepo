#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; vector<int> d(3);
    cin >> n >> d[0] >> d[1] >> d[2];
    ll ans = n / (d[0] + d[1] + d[2]) * 3; 
    ll tot = n - n % (d[0] + d[1] + d[2]);
    for(int i = 0; i < 3; i++)
        if(tot < n) ans++, tot += d[i];
        else break;
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
