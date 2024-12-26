#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 10; // TODO

int n, q, tot;
int I[maxn], Z[maxn];
int ds[maxn];
int ans[maxn];
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            I[i + 1] = 1;
        else if (s[i] == '2')
            Z[i + 1] = 1;
        else if (s[i] == '/')
            ds[++tot] = i + 1;

        I[i + 1] += I[i + 1 - 1];
        Z[i + 1] += Z[i + 1 - 1];
    }
    // 记录所有'/'的位置. 对于每个询问, 二分[l, r]中的'/'
    // check(i) 检查位于s[i - 1]位置的'/'
    for (int i = 1; i <= q; i++) {
        int ql, qr;
        cin >> ql >> qr;

        int l = lower_bound(ds + 1, ds + tot + 1, ql) - (ds + 1) + 1;
        int r = upper_bound(ds + 1, ds + tot + 1, qr) - (ds + 1) + 1;
        r--;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (I[ds[mid]] - I[ql - 1] >= Z[qr] - Z[ds[mid] + 1 - 1])
                r = mid;
            else
                l = mid + 1;
        }
        auto count = [&](int idx) {
            if (idx < 1 || idx > tot || ds[idx] < ql || ds[idx] > qr)
                return 0;
            return max(0, 1 + 2 * min(I[ds[idx]] - I[ql - 1], Z[qr] - Z[ds[idx] + 1 - 1]));
        };
        cout << max({count(l - 1), count(l), count(l + 1)}) << '\n';
        /*
for(int j = l; j <= r; j++) {
    if(s[j - 1] == '/') {
        ans = max(ans, min(I[j - 1] - I[l - 1], Z[r] - Z[j - 1]) * 2 + 1ll);
    }
}
cout << ans << '\n';
*/
    }
    return 0;
}
