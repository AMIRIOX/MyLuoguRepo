#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
int a[maxn], b[maxn], c[maxn], d[maxn];
int n1, n2, n3, n4, ansp, ans, n;
int *p;
// 你只管深搜枚举, 剩下的交给min/max
void dfs(int cur, int left, int right) {
    if(cur > n) {
        ansp = min(ansp, max(left, right));
        return; 
    }
    dfs(cur + 1, left + p[cur], right);
    dfs(cur + 1, left, right + p[cur]);
}
signed main() {
    cin >> n1 >> n2 >> n3 >> n4;
    for(int i = 1; i <= n1; i++) cin >> a[i];
    for(int i = 1; i <= n2; i++) cin >> b[i];
    for(int i = 1; i <= n3; i++) cin >> c[i];
    for(int i = 1; i <= n4; i++) cin >> d[i];

    ansp = 0x7fffffff;
    p = a; n = n1;
    dfs(1, 0, 0);
    ans += ansp;

    ansp = 0x7fffffff;
    p = b; n = n2;
    dfs(1, 0, 0);
    ans += ansp;

    ansp = 0x7fffffff;
    p = c; n = n3;
    dfs(1, 0, 0);
    ans += ansp;

    ansp = 0x7fffffff;
    p = d; n = n4;
    dfs(1, 0, 0);
    ans += ansp;

    cout << ans << endl;
    return 0;
}
