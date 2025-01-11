#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int i = 1, j = (n + 1) / 2;
    ll ans = 0;
    while(i <= n / 2 && j <= n) {
        if(a[i] * 2 <= a[j]) {
            ans++; i++; j++;
        }else {
            j++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

