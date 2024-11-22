#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e4 + 10;
int a[maxn][maxn];
int sum[maxn][maxn];
inline int area(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    int ans = -0x7fffffff;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = i; k <= n; k++) {
                for(int l = j; l <= n; l++) {
                    ans = max(ans, area(i, j, k, l));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
