// 不是你妈b的口胡的纯暴力这都能过的
// 合着 cf div2B 就都是骗复杂度的模拟呗?

/*
k == n:
    所有数字自成一个子数组
    偶数位置上就是 b, O(n) 找 cost 即可

k < n:
    子数组的最大长度可以是 n - (k - 1), 但这个长度的只能有一个
    1 1 1 2 2 (k=4)
    1 1, 1, 2, 2
    1, 1 1, 2, 2

    1 1 INF 2 2 

    找 [2, n - (k - 1) + 1] 开始的[1, 2, 3...]连续最短序列

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }

    if (n == k) {
        int val = 0, i = 2;
        for (; i <= n; i += 2) {
            if (a[i] == val + 1) val++;
            else break;
        }
        cout << val + 1 << '\n';
        return;
    }

    int ans = 0x7fffffff;
    for(int dt = 1; ans == 0x7fffffff; dt++) {
        for (int i = 1 + dt; i <= min(n - (k - 1) + dt, n); i++) {
            int val = 0;
            for (int j = i; j <= n; j++) {
                if (a[j] == val + 1) val++;
                else break;
            }
            if (val + 1 <= n - (k - 1))
                ans = min(ans, val + 1);
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
