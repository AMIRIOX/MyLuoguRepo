// 区间修改 单点查询 （差分&前缀和树状数组）
#include <cstdio>
#include <iostream>
#define int long long
#define lowbit(x) ((x) & (-x))
const int maxn = 5e5 + 10;
using namespace std;
int t[maxn], n, m, a[maxn];
void add(int x, int v) {
    for (; x <= n; x += lowbit(x))
        t[x] += v;
}
int ask(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += t[x];
    return ans;
}
// void build() {
//     for (int i = 1; i <= n; i++)
//         add(i, a[i]);
// }
signed main() {
    scanf("%lld %lld", &n, &m);
    int last = 0, now;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &now);
        add(i, now - last);
        last = now;
    }
    for (int i = 1; i <= m; i++) {
        int cmd, hu, hv, hk;
        scanf("%lld %lld", &cmd, &hu);
        if (cmd == 1) {
            scanf("%lld %lld", &hv, &hk);
            add(hu, hk);
            add(hv + 1, -hk);
        } else {
            printf("%lld\n", ask(hu));
        }
    }
    return 0;
}
