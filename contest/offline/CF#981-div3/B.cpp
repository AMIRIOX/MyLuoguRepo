#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1000;
int a[maxn][maxn];
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    long long ans = 0;
    for(int x = n; x >= 1; x--) {
        int pans = 0;
        for(int j = 0; x + j <= n && 1 + j <= n; j++) {
            int cur = a[x + j][1 + j];
            if(cur < 0) pans = max(pans, abs(cur)); 
        }
        ans += pans;
    }
    for(int y = 2; y <= n; y++) {
        int pans = 0;
        for(int i = 0; 1 + i <= n && y + i <= n; i++) {
            int cur = a[1 + i][y + i];
            if(cur < 0) pans = max(pans, abs(cur));
        }
        ans += pans;
    }
    cout << ans << endl;
}
signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
