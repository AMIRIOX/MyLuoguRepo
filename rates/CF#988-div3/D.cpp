// !unaccepted MLE on #4
// It's a pile of well-styled shit.
/*
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;

    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) { 
        return a.first < b.first; 
    };
    set<pair<int, int>, decltype(cmp)> rg(cmp);

    priority_queue<int, vector<int>, less<int> > q;
    map<int, int> mp; int k = 0;
    vector<vector<int> > a(1);
    
    for(int i = 1; i <= n; ++i) {
        int l, r; cin >> l >> r;
        rg.insert(pair<int, int>(l, r));
    }

    for(int i = 1; i <= m; ++i) {
        int x, v; cin >> x >> v;
        if(!mp[x]) {
            mp[x] = ++k;
            a.push_back(vector<int>{v});
        }else a[mp[x]].push_back(v);
    }
    long long ans = 0;
    long long dt = 1;
    for(int i = 1; i <= L; i++) {
        if(mp[i] && mp[i] < a.size()) 
            for(int j = 0; j < a[mp[i]].size(); j++) 
                q.push(a[mp[i]][j]);
        auto it = rg.begin();
        if(it != rg.end() && it->first == i + 1) {
            int dti = it->second - it->first + 1;
            while(dt <= dti) {
                if(q.empty()) {
                    cout << -1 << '\n';
                    return;
                }
                ans++;
                dt += q.top();
                q.pop();
            }
            i = it->second;
            rg.erase(it);
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
*/

// TODO: difference between 2f and grd
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;

    vector<int> l(n + 1), r(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }

    vector<int> x(m + 1), v(m + 1);
    for(int i = 1; i <= m; ++i) {
        cin >> x[i] >> v[i];
    }

    priority_queue<int, vector<int>, less<int> >q;
    long long k = 1;
    long long ans = 0;
    for(int i = 1, j = 1; i <= n; i++) {
        while(j <= m && x[j] < l[i]) q.push(v[j++]);
        int len = r[i] - l[i] + 1;
        while(k <= len) {
            if(q.empty()) {
                cout << -1 << '\n';
                return;
            }
            ans++;
            k += q.top();
            q.pop();
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}
