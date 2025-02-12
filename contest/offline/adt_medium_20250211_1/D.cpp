#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Student {
    int idx, m, e;
};
void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<Student> a(n);
    for (int i = 0; i < n; i++)
        a[i].idx = i + 1;
    for (int i = 0; i < n; i++)
        cin >> a[i].m;
    for (int i = 0; i < n; i++)
        cin >> a[i].e;
    sort(a.begin(), a.end(),
         [&](auto &i, auto &j) { return (i.m == j.m ? i.idx < j.idx : i.m > j.m); });
    int pos = 0;
    set<int> s;
    while(x--) 
        s.insert(a[pos++].idx);
    sort(a.begin() + pos, a.end(),
         [&](auto &i, auto &j) { return (i.e == j.e ? i.idx < j.idx : i.e > j.e); });
    while(y--)
        s.insert(a[pos++].idx);
    sort(a.begin() + pos, a.end(), [&](auto &i, auto &j) {
        return (i.m + i.e == j.m + j.e ? i.idx < j.idx : i.m + i.e > j.m + j.e);
    });
    while(z--) 
        s.insert(a[pos++].idx);

    for(auto &&i : s) cout << i << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
