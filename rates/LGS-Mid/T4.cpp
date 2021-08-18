#include <cstdio>
#include <iostream>
using namespace std;
int n, l, r, ans = 0x7fffffff;
int a[1200], b[1200];
void dfs(int last /*0 for country, 1 for revolution*/,
         int lng,
         int lv,
         int ck) {
    if (lv > n) {
        if (lng >= l && lng <= r)
            ans = min(ans, ck);
        return;
    }
    if (lng < l) {
        // cannot open a new space
        dfs(last, lng + 1, lv + 1, ck + (last ? b[lv] : a[lv]));
    } else if (lng >= r) {
        // must open a new space
        dfs(!last, 1, lv + 1, ck + (last ? a[lv] : b[lv]));
    } else if (lng >= l && lng < r) {
        // two choice
        dfs(last, lng + 1, lv + 1, ck + (last ? b[lv] : a[lv]));
        dfs(!last, 1, lv + 1, ck + (last ? a[lv] : b[lv]));
    }
}
signed main() {
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    dfs(0, 0, 1, 0);
    dfs(1, 0, 1, 0);
    if (ans != 0x7fffffff)
        printf("%d\n", ans);
    else
        printf("NO ANSWER\n");
    return 0;
}