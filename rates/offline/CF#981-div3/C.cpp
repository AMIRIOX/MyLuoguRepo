#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 10;
int n;
int a[maxn];

void solve() {
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // only touch a1 ~ an/2
    for(int i = 2; i <= n; i++) {
        if(a[i] == a[i - 1] || a[n - i + 1] == a[n - i + 1 + 1]) {
            swap(a[i], a[n - i + 1]);
        }
    }

    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans += (a[i] == a[i + 1]);
    }

    cout << ans << endl;
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
