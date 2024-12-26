// !unaccepted TLE
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int maxn = 2e5 + 10;
int a[maxn], b[maxn], ans[maxn];

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    std::list<int> l;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        l.push_back(i);
    }
    for(int i = 1; i <= n; i++)
    for(auto iter = l.begin(); iter != l.end();) {
        if(b[*iter] >= a[i]) {
            ans[*iter] = i;
            iter = l.erase(iter);
            continue;
        }
        iter++;
    }
    
    for(int i = 1; i <= m; i++) {
        if(!ans[i]) { printf("-1\n"); }
        else { printf("%d\n", ans[i]); }
    }
    
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5 + 10;
int a, b, ans[maxn];
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int sushi = maxn - 1;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        while(sushi >= a) {
            ans[sushi] = i;
            sushi--;
        }
    }
    for(int i = 1; i <= m; i++) {
        cin >> b;
        if(!ans[b]) cout << -1 << '\n';
        else cout << ans[b] << '\n';
    }
    return 0;
}
