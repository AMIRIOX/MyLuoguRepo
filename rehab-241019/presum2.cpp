#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int maxn = 2e5 + 10;
int a[maxn];

void solve() {
    int n, k;
    cin >> n >> k;
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    int maxk = -0xffffffffff, ans = -0xffffffffff;
    for(int i = k; i + k <= n; i++) {
        // [i - k + 1, i]   [i + 1, i + k]
        maxk = max(maxk, a[i] - a[i - k + 1 - 1]);
        ans = max(ans, maxk + a[i + k] - a[i + 1 - 1]);
    }
    cout << ans << endl;
}

signed main(void) {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}