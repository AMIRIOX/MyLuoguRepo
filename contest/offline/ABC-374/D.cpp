#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

struct seg {
    int x1, y1;
    int x2, y2;
};

double dis(int x1, int y1, int x2, int y2) {
    double a = x2 - x1;
    double b = y2 - y1;
    return sqrt(a * a + b * b);
}
void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<seg> in(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> in[i].x1 >> in[i].y1 >> in[i].x2 >> in[i].y2;
    }
    vector<int> permu;
    for(int i = 1; i <= n; i++) permu.push_back(i);

    double ans = 2e16;
    auto dfs = [&](auto &&self, int p, double ds, double dt, int cx = 0, int cy = 0) -> void {
        if(p == n) {
            ans = min({ans, ds / s + dt / t});
            return;
        }
        auto cur = in[permu[p]];
        self(self, p + 1, ds + dis(cx, cy, cur.x1, cur.y1), 
                          dt + dis(cur.x1, cur.y1, cur.x2, cur.y2), cur.x2, cur.y2);
        self(self, p + 1, ds + dis(cx, cy, cur.x2, cur.y2), 
                          dt + dis(cur.x2, cur.y2, cur.x1, cur.y1), cur.x1, cur.y1);
    };
    do {
        dfs(dfs, 0, 0, 0);
    }while(next_permutation(permu.begin(), permu.end()));

    cout << fixed << setprecision(18) << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}

