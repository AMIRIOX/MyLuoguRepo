/* WA
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct guest {
    ll a;
    ll b;
    bool operator<(const guest &g) {
        if (this->b != g.b)
            return this->b > g.b;
        else
            return this->a > g.a;
    }
};
ll n, k;
ll check(vector<guest> &gst, ll price) {
    ll trees = upper_bound(gst.begin(), gst.end(), price, [](const ll &prc, const guest &g) {
        return g.b < prc;
            }) - gst.begin();
    ll neg = upper_bound(gst.begin(), gst.end(), price, [](const ll &prc, const guest &g) {
        return g.a < prc;
            }) - gst.begin();
    neg = trees - neg;
    cout << price << " " << trees << " " << neg << endl;
    if(neg <= k) return price * trees;
    else return -1;
}

void solve() {
    cin >> n >> k;
    vector<guest> gst(n + 1);
    for (int i = 0; i < n; i++)
        cin >> gst[i].a;
    for (int i = 0; i < n; i++)
        cin >> gst[i].b;
    sort(gst.begin(), gst.end());
    ll ans = -1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, check(gst, gst[i].a));
        ans = max(ans, check(gst, gst[i].b));
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
*/

#ifdef SOL_1
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll ans = -1;
    auto check = [&](ll price) {
        ll neg = lower_bound(a.begin(), a.end(), price) - a.begin();
        neg -= lower_bound(b.begin(), b.end(), price) - b.begin();
        ll tot = lower_bound(b.begin(), b.end(), price) - b.begin();
        tot = n - tot;
        if(neg <= k) return price * tot;
        else return -1ll;
    };
    for(int i = 0; i < n; i++) {
        ans = max(ans, check(a[i]));
        ans = max(ans, check(b[i]));
    }
    cout << ans << '\n';
}

signed main() {
    int tt = 1; cin >> tt;
    while(tt--) solve();
}

#endif

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    
    vector<pair<ll, int>> events;
    for(int i = 0; i < n; i++) {
        events.emplace_back(a[i], 1);
        events.emplace_back(b[i], 2);
    }
    sort(events.begin(), events.end());
    int cnt = n, bad = 0;
    ll ans = 0;
    for(int i = 0; i < 2 * n; ) {
        auto [price, stat] = events[i];
        if(bad <= k) ans = max(ans, cnt * price);
        while(i <= 2 * n && events[i].first == price) {
            bad += (events[i].second == 1);
            bad -= (events[i].second == 2);
            cnt -= (events[i].second == 2);
            ++i;
        }
    }
    cout << ans << '\n';
}

signed main() {
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
