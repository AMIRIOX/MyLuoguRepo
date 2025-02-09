#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

int tmp1;
void solve() {
    int n;
    cin >> n;
    vector dice(n, vector<int>());
    vector count(n, unordered_map<int, int>());
    for (int i = 0; i < n; i++) {
        cin >> tmp1;
        dice[i].resize(tmp1);
        for (int j = 0; j < tmp1; j++) {
            cin >> dice[i][j];
            count[i][dice[i][j]]++;
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double tans = 0;
            for (auto &[k, c] : count[i]) {
                if(count[j].count(k))
                    tans += 1LL * c * count[j][k];
            }
            tans *= 1.0 / (dice[i].size() * dice[j].size());
            ans = max(ans, tans);
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
