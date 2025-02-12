#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    int a, n;
    cin >> a >> n;
    int maxb = log10(n) + 1;

    unordered_map<int, bool> vis;
    queue<pair<int, int>> q;

    q.push({1, 0});
    vis[1] = true;
    int ans = -1;
    while (!q.empty()) {
        auto [num, cnt] = q.front();
        q.pop();

        if (num == n) {
            ans = cnt;
            break;
        }

        int nxt = num * a;
        if (!vis.count(nxt) && floor(log10(nxt)) + 1 <= maxb) {
            q.push({nxt, cnt + 1});
            vis[nxt] = true;
        }

        if (num >= 10 && num % 10) {
            string tmp = to_string(num);
            tmp = tmp.back() + tmp;
            tmp.pop_back();
            nxt = atoi(tmp.c_str());
            if (!vis.count(nxt) && floor(log10(nxt)) + 1 <= maxb) {
                q.push({nxt, cnt + 1});
                vis[nxt] = true;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
