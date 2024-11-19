#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100;
int vis[maxn], visc[maxn], visx[maxn];
int a[maxn];
int n;
long long ans = 0;
void dfs(int cur) {
    if(cur == n + 1) {
        ans++;
        if(ans <= 3) {
            for(int i = 1; i <= n; ++i) cout << a[i] << " "; //printf("%d ", a[i]);
            cout << endl;
        }
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(vis[i] || visc[cur + i] || visx[cur - i + n]) continue;
        a[cur] = i;
        vis[i] = visc[cur + i] = visx[cur - i + n] = 1;
        dfs(cur + 1);
        vis[i] = visc[cur + i] = visx[cur - i + n] = 0;
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n;
    dfs(1);
    cout << ans << endl;
}
