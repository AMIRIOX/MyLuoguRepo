#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i - 1]) == 1 && (a[i] == (i - 1) + 1 || a[i - 1] == (i) + 1)) {
            swap(a[i], a[i -1]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != i + 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
