#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) cin >> i;

    vector<int> ans1(n, -1);
    queue<int> dq;
    for(int i = 0; i < n; i++) {
        while(!dq.empty() && dq.front() <= a[i]) dq.pop();
        int tmp = (dq.empty() ? a[i] : dq.front());
        ans1[i] = (tmp > a[i] ? tmp : a[i]);
        dq.push(a[i]);
    }

    vector<int> ans2(n, -1);
    set<int> pq;
    for(int i = n - 1; i >= 0; i--) {
        auto tmp = lower_bound(pq.begin(), pq.end(), a[i]);
        if(tmp == pq.begin()) ans2[i] = a[i];
        else {
            int tgt = *(--tmp);
            ans2[i] = max(tgt, ans1[tgt]);
        }
        pq.insert(a[i]);
    }

    for(int i = 0; i < n; i++) cout << max(ans1[i], ans2[i]) << " ";
    // for(int i = 0; i < n; i++) cout << ans2[i] << " ";
    cout << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
