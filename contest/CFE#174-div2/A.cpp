#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n, -1);
    vector<int> b(n, 0);
    // 0, 1, 2, ..., n - 1
    for(int i = 1; i < n - 1; i++) {
        cin >> b[i];
    }
    bool ok = true; a[0] = 1;
    for(int i = 1; i < n - 1; i++) {
        if(!b[i]) {
            if(a[i] == -1) {
                a[i] = a[i - 1] + 1;
            }else {
                if(a[i] == a[i - 1]) {
                    a[i + 1] = a[i] + 1;
                }
            }
        }else {
            if(a[i] == -1) {
                a[i + 1] = a[i] = a[i - 1];
            }else {
                if(a[i] != a[i - 1]) {
                    ok = false;
                    break;
                }else a[i + 1] = a[i];
            }
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
