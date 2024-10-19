#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e8 + 10;
int a, b[maxn], ans;
signed main() {
    int l, m;
    cin >> l >> m;
    for(int i = 1; i <= m; i++) {
        int l0, r0;
        cin >> l0 >> r0;
        b[l0]++;
        b[r0 + 1]--;
    }
    for(int i = 0; i <= l; i++) {
        a += b[i];
        if(!a) ans++;
    }
    cout << ans << endl;
    return 0;
}