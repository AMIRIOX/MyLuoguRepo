#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll fact[] = {1, 1, 2, 6, 24, 120};
void solve() {
    ll n, d;
    cin >> n >> d;
    // 1 3 5 7 9
    cout << 1 << ' ';
    if (d % 3 == 0 || n >= 3)
        cout << 3 << ' ';
    if (d == 5)
        cout << 5 << ' ';
    if (n >= 6) cout << 7 << ' ';
    else {
        ll rem = fact[n] % 6;
        if(rem == 1 && d * 4 % 7 == 0) cout << 7 << ' ';
        else if(rem == 2 && d * 6 % 7 == 0) cout << 7 << ' ';
        else if(rem == 3 && d * 5 % 7 == 0) cout << 7 << ' ';
        else if(rem == 4 && d * 2 % 7 == 0) cout << 7 << ' ';
    }
    ll cnt3 = 0;
    if (n >= 3) cnt3++;
    if (n >= 6) cnt3++;
    if (d % 3 == 0) cnt3++;
    if (d == 9) cnt3++;
    if(cnt3 >= 2) cout << 9;
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
