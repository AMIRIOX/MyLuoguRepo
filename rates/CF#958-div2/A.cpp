
/*
#include <bits/stdc++.h>
using namespace std;

int calc(int n, int k) {
    if(n <= 1) return 0;
    if(n <= k) return 1;
    return n / k + calc(n / k, k) + int((n - n / k * k) > 1) + int((n - n / k * k) > 0);
}

void solve() {
    int n = 0, k = 0; cin >> n >> k;
    if(n == 1) cout << 0 << endl;
    else cout << calc(n / k * k, k) + int((n - n / k * k) > 1) + int((n - n / k * k) > 0) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, k = 0;
    cin >> n >> k;
    cout << ((n - 1 + k - 2)/(k - 1)) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
