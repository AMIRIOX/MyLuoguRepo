#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> paired(n);

    for (auto &i : a)
        cin >> i;

    ll ans = 0;
    for(int i = n / 2; i >= 1; i--) {
        auto it = upper_bound(a.begin(), a.begin() + i + 1, a[i] / 2);
        if(it == a.begin()) continue;

        while(--it >= a.begin()) {
            if(paired[it - a.begin()]) continue;
            ans++;
            paired[it - a.begin()] = 1;
            break;
        }
        //cout << "found " << *it << " paired with " << a[i] << endl;
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

