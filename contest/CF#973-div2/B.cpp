#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    // 给定a1 ~ an, 每次取i<j,
    // 淘汰 ai, 令aj - ai
    // 求剩下最大的 aj
    int n = 0; 
    cin >> n;
    vector<int> v(n);
    for(auto &ai: v) cin >> ai;
    int ans = 0;
    for(int i = 0; i < n; i++) ans += v[i];
    cout << ans - 2 * v[n - 2] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
