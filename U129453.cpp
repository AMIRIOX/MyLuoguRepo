#include <cstdio>
#include <iostream>
#define INF 0x7fffffff
// #define int long long
using namespace std;
const int MAXN = 1e6 + 1;
int a[MAXN], n, k, ans = 1;
int d(int x) {
    int cnt = 0, cnt2 = 0;
    bool ar = false;
    for (int i = x;; i = (i == 1) ? n : i - 1) {
        if (a[i] != 0 && ar) break;
        cnt++;
        ar = true;
    }
    ar = false;
    for (int i = x;; i = (i == n) ? 1 : i + 1) {
        if (a[i] != 0 && ar) break;
        cnt2++;
        ar = true;
    }
    return min(cnt - 1, cnt2 - 1);
}
signed main() {
    cin >> n >> k;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    a[1] = 1;
    while (1) {
        int maxd = -INF;
        int maxi = -INF;
        // cout << "now is " << ans << endl;
        for (int i = 1; i <= n; i++) {
            if(a[i]!=0) continue;
            a[i] = 1;
            int nowd = d(i);
            // cout << "in " << i << " the nowd is " << nowd << endl;
            if (nowd > maxd) {
                maxd = nowd;
                maxi = i;
            }
            a[i] = 0;
        }
        // cout << "maxd is " << maxd  << " maxi is " << maxi << endl;
        if (maxd < k) break;
        a[maxi] = 1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}