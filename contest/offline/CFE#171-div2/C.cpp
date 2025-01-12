#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = c - '0';
        sum += i;
    }
    
    int tag = n - 1, tag1 = 1;
    for(int i = n; i > 1; i--) {
        if(a[i] != 1) continue;
        if(tag > i) tag = i - 1;
        while(tag >= 1 && a[tag] != 0) tag--;
        if(tag >= 1) {
            a[tag] = -1;
            sum -= i;
        }else {
            while(tag1 < i && a[tag1] != 1) tag1++;
            if(tag1 < i) {
                a[tag1] = -1;
                sum -= i;
            }
        }
    }
    cout << sum << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}
