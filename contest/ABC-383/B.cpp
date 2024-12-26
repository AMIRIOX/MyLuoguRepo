#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll h, w, d;
char s[50][50];
bool vis[50][50];
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> h >> w >> d;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> s[i][j];
        }
    }
    ll ans = 0;
    auto ok = [&](int i, int j, int dx, int dy, function<int(int, int)> op1,
                  function<int(int, int)> op2) {
        return (op1(i, dx) >= 1 && op1(i, dx) <= h && op2(j, dy) >= 1 && op2(j, dy) <= w);
    };
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = i; k <= h; k++) {
                for (int l = j; l <= w; l++) {
                    if (i == k && j == l)
                        continue;
                    if (s[i][j] != '.' || s[k][l] != '.')
                        continue;
                    memset(vis, 0, sizeof vis);
                    ll ansi = 0;
                    auto calc = [&](int ii, int jj, function<int(int, int)> op1,
                                    function<int(int, int)> op2) {
                        for (int p = 0; p <= d; p++) {
                            for (int q = 0; q <= d; q++) {
                                if(p + q > d) continue;
                                if (ok(ii, jj, p, q, op1, op2) &&
                                    s[op1(ii, p)][op2(jj, q)] == '.' &&
                                    !vis[op1(ii, p)][op2(jj, q)]) {
                                    ansi++;
                                    vis[op1(ii, p)][op2(jj, q)] = true;
                                }
                            }
                        }
                    };
                    auto addop = [](int aa, int bb) { return aa + bb; };
                    auto minop = [](int aa, int bb) { return aa - bb; };
                    calc(i, j, addop, minop);
                    calc(i, j, minop, addop);
                    calc(i, j, addop, addop);
                    calc(i, j, minop, minop);

                    calc(k, l, addop, minop);
                    calc(k, l, minop, addop);
                    calc(k, l, addop, addop);
                    calc(k, l, minop, minop);
                    ans = max(ansi, ans);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
