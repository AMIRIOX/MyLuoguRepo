#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> a(n);
    vector<int> cnt(60);
    for(auto &i: a) {
        cin >> i;
        cnt[i]++;
    }
    for(auto i: a) {
        if(cnt[i] % 2) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
