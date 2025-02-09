#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    sort(b.begin(), b.end());

    // 1. 在大于等于前一位的前提下尽可能小
    // 2. 如果小于前一位, 尽可能小地刚好增大到前一位
    // 5 6 4
    if (b[0] - a[0] < a[0])
        a[0] = b[0] - a[0];
    for (int i = 1; i < n; i++) {
        // min {b[j] - a[i]} >=a[i-1]
        auto it = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
        int bs = 0;
        if(it != b.end()) {
            bs = *it;
            if (bs - a[i] >= a[i - 1] && bs - a[i] < a[i]) {
                a[i] = bs - a[i];
            }
        }
        if (a[i] < a[i - 1]) {
            if (it != b.end() && bs - a[i] >= a[i - 1]) {
                a[i] = bs - a[i];
            } else {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
