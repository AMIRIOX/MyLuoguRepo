#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    cout << n - q << '\n';
    unordered_map<int, bool> vis;
    while(q--) {
        int tmp; cin >> tmp;
        vis[tmp] = true;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) cout << i << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

