// 35ms.

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;
struct edge {
    int x, y, v;
} e[maxn];

int n, m, tot, ans;
int fa[maxn];

int read() {
    int flg = 1, val = 0;
    char ch = (char) getchar_unlocked();
    while(ch < '0' || ch > '9') {
        if(ch == '-') flg = 0;
        ch = (char) getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char) getchar_unlocked();
    }
    return (flg ? val : ~(val - 1));
}

inline int find(int x) {
    // return x == fa[x] ? x : fa[x] = find(fa[x]);
    while(__builtin_expect(x != fa[x], 1))
        x = fa[x] = fa[fa[x]];
    return x;
}

void kruskal() {
    sort(e + 1, e + m + 1, [&](const edge& a, const edge& b) { return a.v < b.v; });
    for(int i = 1; i <= m; ++i) {
        int uex = find(e[i].x), uey = find(e[i].y);
        if (uex == uey) continue;
        ans += e[i].v;
        fa[uex] = uey;
        if (++tot == n - 1) break;
    } 
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    n = read(); m = read();
    for(int i = 1; i <= n; ++i) fa[i] = i;

    for(int i = 1; i <= m; ++i) {
        e[i].x = read();
        e[i].y = read();
        e[i].v = read();
    }

    kruskal();
    if(tot == n - 1) printf("%d\n", ans);
    else printf("IMP0SSIBLE\n");

    return 0;
}

