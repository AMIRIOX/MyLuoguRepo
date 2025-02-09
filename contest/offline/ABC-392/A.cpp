#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector in(3, 0);
    for(auto &i : in) cin >> i;
    sort(in.begin(), in.end());
    cout << (in[0] * in[1] == in[2] ? "Yes" : "No") << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

