#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k; cin >> k;
    vector<int> a(k);
    map<int, int> cnt;
    for(auto &i: a) {
        cin >> i;
        cnt[i]++;
    }
    // calc n * m == (k - 2)
    for(auto i: a) {
        int tg = (k - 2) / i;
        if((k - 2) % i == 0 && cnt[tg]) {
            if(tg == i && cnt[tg] < 2) continue;
            cout << i << " " << (k - 2) / i << endl;
            return;
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
