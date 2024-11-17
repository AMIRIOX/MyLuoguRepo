#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100;
void solve() {
    int n;
    cin >> n;
    vector<int> cnt(maxn, 0);
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }
    long long ans = 0;
    for(int i = 1; i < 100; i++) {
        ans += (cnt[i] / 2);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
