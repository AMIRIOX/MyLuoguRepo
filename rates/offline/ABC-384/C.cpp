#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

constexpr char trans[] = {' ', 'A', 'B', 'C', 'D', 'E'};
constexpr int maxn = 50;

vector<int> p(6);
int vis[maxn];

struct ps{
    string name;
    int val;
    ps(const string& _name = "", const int _val = 0) : name(_name), val(_val) {}
    bool operator>(const ps &b) const {
        return val > b.val;
    }
};
vector<ps> ans;

void dfs(int cur) {
    if(cur > 5) {
        string _n; int _v = 0;
        for(int i = 1; i <= 5; i++) if(vis[i]) { _n += trans[i]; _v += p[i]; }
        ans.push_back(ps(_n, _v));
        return;
    }
    vis[cur] = 1;
    dfs(cur + 1);
    vis[cur] = 0;
    dfs(cur + 1);
}

void solve() {
    for(int i = 1; i <= 5; i++) { cin >> p[i]; }
    dfs(1);
    stable_sort(ans.begin(), ans.end(), std::greater());
    for(const auto &ansi : ans) {
        cout << ansi.name << '\n';
    }
    endl(cout);
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
    return 0;
}
