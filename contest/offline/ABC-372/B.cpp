#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int m = 0; cin >> m;
    vector<int> ans;
    while(m > 0) {
        int base = 1, p = 0;
        while(base < m) {
            p++;
            base *= 3;
        }
        if(base != m) p--;
        ans.push_back(p);
        m -= pow(3, p);
    }
    cout << ans.size() << '\n';
    for(const auto &i : ans) {
        cout << i << ' ';
    }
    endl(cout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

