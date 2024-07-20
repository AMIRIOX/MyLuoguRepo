#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> a;
    vector<string> b;
    for(int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    for(int i = 0; i < n; i++) {
        int suma = 0, sumb = 0;
        for(int j = 0; j < m; j++) {
            suma += a[i][j] - '0';
            sumb += b[i][j] - '0';
        }
        if(suma % 3 != sumb % 3) {
            cout << "NO" << endl;
            return;
        }
    }

    for(int j = 0; j < m; j++) {
        int suma = 0, sumb = 0;
        for(int i = 0; i < n; i++) {
            suma += a[i][j] - '0';
            sumb += b[i][j] - '0';
        }
        if(suma % 3 != sumb % 3) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
