#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    double sum = 0;
    vector<double> a(n);
    for(auto &i: a) { cin >> i; sum += i; }

    if(n < 3) {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    
    size_t mid = n / 2;
    // a[mid] < (sum + x) / n / 2
    int ans = a[mid] * n * 2 - sum + 1;
    if(ans <= 0) cout << 0 << endl;
    else cout << ans << endl;
}

signed main(void) {
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
