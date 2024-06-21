// 第k次操作后的ai
// ai = (i-k) | (i-k+1) |...| (i+k)

#include <bits/stdc++.h>
using namespace std;
long long i, k;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 0; cin >> t;
    while(t--) {
        cin >> i >> k;
        long long l = max(0LL, i-k), r = i + k, ans = 0;
        // [31,0] bits
        for(int i=31; ~i; --i) {
            if((l & (1LL<<i)) || (r & (1LL<<i)) || (l>>(i+1)) != (r>>(i+1))) {
                ans |= (1LL<<i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
