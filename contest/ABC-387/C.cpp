#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll qpower(ll a, int p) {
    // calc a^p
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans *= a;
        a *= a;
        p >>= 1;
    }
    return ans;
}
ll calc(ll a) {
    if(!a) return 0;
    const string str = to_string(a);
    const int lead = str[0] - '0', n = str.size();
    auto check = [&](const string &s) {
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i] >= s[0])
                return false;
        }
        return true;
    };

    ll ans = 0;
    if (check(str)) ans++;

    for (int i = 1; i < n; i++) {
        for (int fst = 1; fst <= 9; fst++)
            ans += qpower(fst, i - 1);
    }
    for (int fst = 1; fst < lead; fst++) ans += qpower(fst, n - 1);
    for (int k = 1; k < n; k++) {
        ans += 1ll * min(str[(k + 1) - 1] - '0', lead) * qpower(lead, n - k - 1);
        if (str[(k + 1) - 1] >= str[0])
            break;
    }

    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    ll l, r;
    cin >> l >> r;
    cerr << calc(r) << ' ' << calc(l - 1) << endl;
    cout << calc(r) - calc(l - 1);
    return 0;
}
// !unfinished
/*
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

inline auto getlen(ll in) -> int {
    return log10(in) + 1;
}

inline auto lenof(ll a, ll len) -> ll {
    return qpower(a, len - 1);
}

void solve() {
    ll l, r;
    cin >> l >> r;

    int la = getlen(l);
    int lb = getlen(r);
    int _a = l / (int)qpower(10, (int)log10(l));
    int _b = r / (int)qpower(10, (int)log10(r));
    string stra = to_string(l);
    string strb = to_string(r);

    vector<ll> fa(100, 0);
    fa[1] = min(_a, stra[la - 1] - '0' + 1);
    for(int i = 2; i <= la; i++) {
        fa[i] = min(_a, stra[la - i] - '0') * (fa[i - 1] + 1);
        cout << i << " " << fa[i] << '\n';
    }

    vector<ll> fb(100, 0);
    fb[1] = min(_b, strb[lb - 1] - '0' + 1);
    for(int i = 2; i <= lb; i++) {
        fb[i] = min(_b, strb[lb - i] - '0') * (fb[i - 1] + 1);
        cout << i << " " << fb[i] << '\n';
    }

    ll ans = 0;
    for(int a = _a; a <= 9; a++) {
        ans += lenof(a, la);
    }
    ans -= fa[la]; ans++;

    for(int len = getlen(l) + 1; len < lb; len++) {
        for(int a = 1; a <= 9; a++) {
            ans += lenof(a, len);
        }
    }
    ans += fb[lb];

    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
*/
