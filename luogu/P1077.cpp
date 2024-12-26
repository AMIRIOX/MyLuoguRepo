#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll mod = 1e6 + 7;
constexpr ll maxn = 150;

int n, m;
int d[maxn][maxn];
int a[maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    // Di,j = Di-1,j-k + k, 0<=k<=ai<=m
    d[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= min(a[i], j); k++) {
                d[i][j] = (d[i][j] + d[i - 1][j - k]) % mod;
            }
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}
