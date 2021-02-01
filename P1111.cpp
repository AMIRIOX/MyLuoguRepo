#ifdef MST_METHOD

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
struct edge {
    int x, y, v;
} e[maxn];
int fa[maxn];  // fa2[maxn];
int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
// int find2(int x) {
//     while (x != fa2[x])
//         x = fa2[x] = fa2[fa2[x]];
//     return x;
// }
int n, m, ans, tot, ansv;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v);
    }
    sort(e + 1, e + m + 1,
         [&](const edge& a, const edge& b) { return a.v < b.v; });
    for (int i = 1; i <= m; i++) {
        int uex = find(e[i].x), uey = find(e[i].y);
        if (uex == uey)
            continue;
        ans += e[i].v;
        ansv = max(ansv, e[i].v);
        fa[uex] = uey;
        ++tot;
        // if (++tot == n - 1)
        //     break;
    }
    // bool ok = true;
    // for (int i = 1; i <= m; i++) {
    //     int uex = find2(e[i].x), uey = find2(e[i].y);
    //     fa2[uex] = uey;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (i == j)
    //             continue;
    //         if (find2(i) != find2(j))
    //             ok = false;
    //     }
    // }
    if (tot == n - 1)
        printf("%d\n", ansv);
    else
        printf("-1\n");
}
#endif

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
struct edge {
    int x, y, v;
} e[maxn];
int fa[maxn];
int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v);
    }
    sort(e + 1, e + m + 1,
         [&](const edge& a, const edge& b) { return a.v < b.v; });
    for (int i = 1; i <= m; i++) {
        int uex = find(e[i].x), uey = find(e[i].y);
        if (uex != uey) {
            fa[uex] = uey;
            n--;
        }
        if (n == 1) {
            printf("%d\n", e[i].v);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
