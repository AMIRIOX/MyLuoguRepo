#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct guest {
    int a;
    int b;
    bool operator<(const guest &g) {
        if (this->a != g.a)
            return this->a > g.a;
        else
            return this->b > g.b;
    }
};
ll n, k;
bool check(vector<ll> &a, vector<ll> &b, ll pris, ll pri) {
    // pri <= ai        tree++
    // ai < pri <= bi  tree++, neg++
    int neg = 0, tree = 0;
}

void solve() {
    cin >> n >> k;
    vector<guest> gst(n + 1);
    for (int i = 0; i < n; i++)
        cin >> gst[i].a;
    for (int i = 0; i < n; i++)
        cin >> gst[i].b;
    sort(gst.begin(), gst.end());
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
