// 单点修改 区间查询
#include <cstdio>
#include <iostream>
const int maxn = 5e5 + 10;
int a[maxn], t[maxn];
int n, m, c;
int lowbit(int x) {
    return (x & -x);
}
void add(int x, int v) {
    // a[x] += v;
    for (; x <= n; x += lowbit(x))
        t[x] += v;
}
int ask(int x) {
    // 1~x
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += t[x];
    return ans;
}
void build() {
    for (int i = 1; i <= n; i++)
        add(i, a[i]);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        // t[i] = i;
    }
    build();
    for (int i = 1; i <= m; i++) {
        int cmd, x, y;
        scanf("%d %d %d", &cmd, &x, &y);
        if (cmd == 1) {
            add(x, y);
        } else {
            printf("%d\n", ask(y) - ask(x - 1));
        }
    }
    return 0;
}
