// 1 <= ai <= n 考虑枚举值域
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, tmp;
    cin >> n;
    unordered_map<int, int> cnt1;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        cnt1[tmp]++;
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int cnt = cnt1[i];
        if (cnt >= 3) {
            cnt1[i + 1] += (cnt - 2);
            cnt1[i] = 2;
        }
        if (cnt1[i] % 2) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
