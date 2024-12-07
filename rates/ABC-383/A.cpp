#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
ll t[120], v[120], mt;
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll ti, vi;
        cin >> ti >> vi;
        t[ti] = vi; 
        mt = max(mt, ti);
    }
    ll ans = 0;

    for(int i = 1; i <= mt; i++) {
        if(ans > 0) ans--;
        ans += t[i];
    }
    cout << ans << '\n';
    return 0;
}
