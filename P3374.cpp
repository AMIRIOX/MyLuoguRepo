#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn], belong[maxn];
int l[maxn], r[maxn];
int sum[maxn], S, C, n, m;
inline int read() {
    int val = 0, flg = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flg = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = getchar();
    }
    return flg * val;
}
inline void build() {
    S = (int)sqrt((double)n);
    C = n / S;
    if (n % S)
        C++;
    for (register int i = 1; i <= C; i++) {
        l[i] = (i - 1) * S + 1;
        r[i] = i * S;
    }
    r[C] = n;
    for (register int i = 1; i <= n; i++) {
        belong[i] = (i - 1) / S + 1;
    }
    for (register int i = 1; i <= C; i++)
        for (int j = l[i]; j <= r[i]; j++) {
            sum[i] += a[j];
        }
}
inline void update(int x, int v) {
    a[x] += v;
    sum[belong[x]] += v;
}
inline int query(int x, int y) {
    int ans = 0;
    if (belong[x] == belong[y]) {
        for (register int i = x; i <= y; i++)
            ans += a[i];
        return ans;
    }
    for (register int i = x; i <= r[belong[x]]; i++)
        ans += a[i];
    for (register int i = belong[x] + 1; i <= belong[y] - 1; i++)
        ans += sum[i];
    for (register int i = l[belong[y]]; i <= y; i++)
        ans += a[i];
    return ans;
}
int main() {
    n = read();
    m = read();
    for (register int i = 1; i <= n; i++)
        a[i] = read();
    build();
    for (register int i = 1; i <= m; i++) {
        int cmd, hu, hv;
        cmd=read();
        hu=read();
        hv=read();
        if (cmd == 1) {
            update(hu, hv);
        } else {
            printf("%d\n", query(hu, hv));
        }
    }
    return 0;
}