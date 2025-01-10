#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0ll);
    for (auto &i : a)
        cin >> i;

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    if (n == 2) {
        cout << a[1] - a[0] << '\n';
        return;
    }

    ll omx = 0, emx = 0;
    for (auto i = 1; i < a.size(); i += 2) {
        ll gap = a[i] - a[i - 1];
        omx = max(omx, gap);

        if (i + 1 < a.size()) {
            ll gap2 = a[i + 1] - a[i];
            emx = max(emx, gap2);
        }
    }

    if (n % 2 == 0) {
        cout << omx << '\n';
    } else {
        ll ans = min(omx, emx);

        ll _cemx = -2e16, _cemx2 = -2e16;
        vector<ll> cemx(n, 0), cemx2(n, 0);
        for (int i = n - 1; i >= 1; i -= 2) {
            ll gapi = a[i] - a[i - 1];
            if (gapi > _cemx) {
                _cemx2 = _cemx;
                _cemx = gapi;
            } else if (gapi > _cemx2) {
                _cemx2 = gapi;
            }
            cemx[i] = _cemx;
            cemx2[i] = _cemx2;
        }

        ll comx = -2e16, comx2 = -2e16;
        for (int i = 1; i < a.size(); i++) {
            ll gapi = a[i] - a[i - 1];
            if (i % 2 != 0) {
                if (gapi > comx) {
                    comx2 = comx;
                    comx = gapi;
                } else if (gapi > comx2) {
                    comx2 = gapi;
                }

                if(gapi == comx) ans = min(max({comx2, /*(comx - 1) / 2*/ 1ll , cemx[i + 1]}), ans);
                // if(ans == 4) cout << ':' << comx2 << ' ' << (comx - 1) / 2 << ' ' << cemx[i + 1] << endl;
            } else {
                if(gapi == cemx[i]) ans = min(max({cemx2[i], /*(cemx[i] - 1) / 2*/ 1ll, comx}), ans);
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
