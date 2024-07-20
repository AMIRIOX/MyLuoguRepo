#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    
    for(auto &i :a) cin >> i;
    for(auto &i :b) cin >> i;
    for(auto &i :c) cin >> i;

    for(int i = 1; i < n; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
        c[i] += c[i-1];
    }

    // sum[l, r]: x[r] - x[l-1]
    // boring 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve(); 
    return 0;
}
