#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    ll odd = 0, even = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (i % 2)
            odd += a[i];
        else
            even += a[i];
    }
    ll tgt = sum / n;
    ll odds = (n + 1) / 2, evens = n / 2;
    if (odd % odds == 0 && even % evens == 0 && odd / odds == tgt && even / evens == tgt) {
        cout << "YES" << endl;
    }else cout << "NO" << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
