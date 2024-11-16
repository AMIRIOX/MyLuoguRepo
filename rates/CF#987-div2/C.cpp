// !unaccepted WA on pretest #2
// solution: if n % 2 (1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2) 14 14 15 15 ...
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
