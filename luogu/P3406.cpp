#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, m;
int p[maxn], a[maxn], b[maxn], c[maxn];
int seg[maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> p[i];
    for(int i = 1; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    for(int i = 1; i < m; i++) {
        // 1 2 3 4
        int l = min(p[i], p[i + 1]), r = p[i] + p[i + 1] - l;
        seg[l]++;
        seg[r]--;
    }
    long long ans = 0, cur = 0;
    for(int i = 1; i < n; i++) {
        cur += seg[i];
        ans += min(c[i] + cur * b[i], cur * a[i]);
    }
    cout << ans << '\n';
    return 0;
}
