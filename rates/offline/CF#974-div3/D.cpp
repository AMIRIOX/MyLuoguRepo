#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int maxn = 2e5 + 10;

int b[maxn];
void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    memset(b, 0, sizeof b);

    // n = 1, d = 1, k = 1
    // 1
    // 1(1)
    // 1 2 3 4 5
    for(int i = 1; i <= k; i++) {
        int l, r;
        cin >> l >> r;
        // 对每个区间分别计算贡献
        b[max(l - d + 1, 1ll)]++; b[r + 1]--;
    }
    
    int ans1 = -0x7fffffff, ans2 = 0x7fffffff;
    int ansi1 = -1, ansi2 = -1;
    for(int i = 1; i <= n - d + 1; i++) {
        b[i] += b[i - 1];
        if(b[i] > ans1) {
            ans1 = b[i];
            ansi1 = i;
        }
        if(b[i] < ans2) {
            ans2 = b[i];
            ansi2 = i;
        }
        // 1 2 3 4 5 6 7 8 9 
        //   2           8
        // 1 1 1 1 1 1 1 1
    }
    
    cout << ansi1 << " " << ansi2 << endl;
}
signed main() {
    int t = 1; cin >> t;
    while(t--) solve();
}
