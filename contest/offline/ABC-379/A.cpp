#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int in = 0; cin >> in;
    vector<short> bits;
    while(in > 0) {
        bits.push_back(in % 10);
        in /= 10;
    }
    // a b c
    // 2 1 0
    cout << bits[1] << bits[0] << bits[2] << ' ';
    cout << bits[0] << bits[2] << bits[1] << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

