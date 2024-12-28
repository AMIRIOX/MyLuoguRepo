#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    int iswhite;
    Point(ll _x, ll _y, bool _isw) : x(_x), y(_y), iswhite(_isw) {}
};
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<Point> mp;

    // 按x顺序排序，每个 当前白色点的j < min(截至目前黑j)
    // 按y升序排序，x递减
    for (int i = 1; i <= m; ++i) {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        mp.push_back(Point(x, y, c == 'W'));
    }

    sort(mp.begin(), mp.end(), [&](const Point &p1, const Point &p2) {
        if (p1.x != p2.x)
            return p1.x < p2.x;
        else if (p1.iswhite != p2.iswhite)
            return p1.iswhite > p2.iswhite;
        else
            return p1.y < p2.y;
    });

    ll curwminy = 2e16;
    for (int i = 0; i < mp.size(); i++) {
        if (mp[i].iswhite)
            curwminy = min(curwminy, mp[i].y);

        if (!mp[i].iswhite && mp[i].y >= curwminy) {
            cout << "No\n";
            return;
        }
    }
    sort(mp.begin(), mp.end(), [&](const Point &p1, const Point &p2) {
        if (p1.y != p2.y)
            return p1.y < p2.y;
        else if (p1.iswhite != p2.iswhite)
            return p1.iswhite > p2.iswhite;
        else
            return p1.x < p2.x;
    });

    ll curwminx = 2e16;
    for (int i = 0; i < mp.size(); i++) {
        if (mp[i].iswhite)
            curwminx = min(curwminx, mp[i].x);

        if (!mp[i].iswhite && mp[i].x >= curwminx) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
