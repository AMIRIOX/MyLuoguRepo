#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 3e5 + 10;
struct knife {
    int hard, val;
} knives[maxn];
int n, m, a[maxn], ans;
bool cmp(knife x, knife y) {
    if (x.hard == y.hard)
        return x.val > y.val;
    else if (x.val == y.val)
        return x.hard > y.hard;
    else {
        return x.val > y.val;
    }
}
signed main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &knives[i].hard, &knives[i].val);
    }
    sort(knives + 1, knives + m + 1, cmp);
    int ind = 1;
    for (int i = 1; i <= n; i++) {
        int vl = knives[ind].val;
        while (knives[ind].hard > a[i] && vl != 0)
            i++;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}