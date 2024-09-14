#include <bits/stdc++.h>
using namespace std;

char vow[5] = {'a', 'e', 'i', 'o', 'u'};
void solve() {
    int n = 0;
    cin >> n;
    for(int c = 0; c < 5; c++) {
        for(int i = 1; i <= n / 5; i++)
            cout << vow[c];
        if(c + 1 <= n % 5) cout << vow[c];
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
