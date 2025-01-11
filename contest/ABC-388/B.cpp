#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, D;
    cin >> N >> D;
    vector<int> t(N + 1), l(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> t[i] >> l[i];
    }
    for(int k = 1; k <= D; k++) {
        int mx = 0;
        for(int i = 1; i <= N; i++) {
            mx = max(mx, t[i] * (l[i] + k));
        }
        cout << mx << '\n';
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

