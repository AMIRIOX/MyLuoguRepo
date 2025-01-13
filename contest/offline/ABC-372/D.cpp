#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n = 0; cin >> n;
    vector<int> h(n);
    for(auto &i : h) cin >> i;
    stack<int> s;
    vector<int> ans(n, 0);
    // 如果计算 ans[i] 时, 存在 i < j < k 且 H[j] > H[k] 则 k 不可能做出贡献
    for(int i = n - 2; i >= 0; i--) {
        while(!s.empty() && h[s.top()] < h[i + 1]) {
            s.pop();
        }
        s.push(i + 1);
        ans[i] = s.size();
    }
    for(const auto &i : ans) cout << i << ' ';
    endl(cout);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
