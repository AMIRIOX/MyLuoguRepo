#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n % 2 == 0) {
        for(int i = 1; i <= n / 2; i++) {
            printf("%d %d ", i, i);
        }
        printf("\n");
    }else {
        printf("-1\n");
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
