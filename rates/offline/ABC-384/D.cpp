// AC

#ifdef SOL_1
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n + 2, 0), presum(n + 2, 0);
    unordered_map<ll, bool> cntfront;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    if (presum[n] == 0) {
        cout << (s == 0 ? "Yes" : "No") << '\n';
    }
    
    cntfront[0] = true;
    for (int i = n; i >= 1; i--)
        cntfront[presum[n] - presum[i - 1]] = true;

    for (int i = 1; i <= n; i++) {
        ll tmp = presum[i - 1];
        if (s < tmp)
            break;
        if (cntfront[(s - tmp) % presum[n]]) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(2 * n + 2, 0), presum(2 * n + 2, 0);
    unordered_set<ll> cntr;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    for(int i = 1; i <= 2 * n; i++) {
        presum[i] = presum[i - 1] + a[i];
    }
    s %= presum[n];
    
    if(!s) {
        cout << "Yes" << '\n';
        return;
    }

    // a1 a2 a3 ... an | 成块的 | a1 a2 a3 ... an
    // 将 a 复制一份, 可以直接将"a的后缀+b的前缀"当成一个"a的连续子段"处理
    // 具体方法如下: 对每个 r 找满足 presum[r] - presum[l] = s 的 l 
    cntr.insert(0);
    for (int i = 1; i <= 2 * n; i++) {
        // presum[r] - presum[l] = s
        if(cntr.count(presum[i] - s)) {
            cout << "Yes" << '\n';
            return;
        }
        cntr.insert(presum[i]);
    }
    cout << "No" << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
