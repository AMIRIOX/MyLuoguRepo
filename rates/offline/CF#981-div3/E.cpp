#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int p[maxn], vis[maxn];

// ~~建图, 并查集求连通分量个数, 对每个连通分量答案贡献是 floor(n/2)-1+n%2 ~~
// 对每个环, 将其拆分为只有一个或两个点, 需要的次数为 x/2-1(偶数) 或 (x+1)/2-1 (奇数) 即为 floor(x-1)/2

void solve() {
    memset(vis, 0, sizeof vis);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    vector<int> v;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int cnt, cur;
            for(cur = p[i], cnt = 0; cur != i; cur = p[cur]) {
                vis[cur] = 1; cnt++;
            }
            ans += (cnt / 2);
        }
    }
    cout << ans << endl;
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
