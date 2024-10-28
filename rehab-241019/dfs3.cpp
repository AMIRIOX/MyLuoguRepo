#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n, s[maxn], b[maxn], ans;


void dfs(int cur, int sums, int sumb, int ch) {
    if(cur > n) {
        if(ch) ans = 
            min(ans, abs(sums - sumb));
        return;
    }
    dfs(cur + 1, sums * s[cur], sumb + b[cur], ch + 1);
    dfs(cur + 1, sums, sumb, ch);
}
signed main() {
    ans = 0x3f3f3f3f;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i] >> b[i];
    dfs(1, 1, 0, 0);
    cout << ans << endl;
    return 0;
}
