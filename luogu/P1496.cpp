#include <bits/stdc++.h>
using namespace std;

int n;
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    map<int, int> m;
    cin >> n;
    int L = 0x7fffffff, R = -0x7fffffff;
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        L = min(L, l);
        R = max(R, r);
        m[l]++;
        m[r]--;
    }
    int cur = 0, ans = 0;
    for(int i = L; i <= R; i++) {
        cur += m[i];
        if(cur) ans++;
    }
    cout << ans << endl;
    return 0;
}
