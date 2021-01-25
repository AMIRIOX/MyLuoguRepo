#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
struct edge {
    int x, y, v;
} e[maxn];
int n, ans, fa[maxn], cnt = 0;
int find(int x) {
    while (fa[x] != x)
        x = fa[x] = fa[fa[x]];
    return x;
}
void kruskal() {
    sort(e + 1, e + (n * (n - 1)) + 1,
         [&](const edge& a, const edge& b) { return a.v < b.v; });
    // for (int i = 1; i <= (n * (n - 1)); i++) {
    //     cout << e[i].x << " " << e[i].y << " = " << e[i].v << endl;
    // }
    for (int i = 1; i <= (n * (n - 1)); i++) {
        int uex = find(e[i].x), uey = find(e[i].y);
        if (uex == uey)
            continue;
        ans += e[i].v;
        fa[uex] = uey;
        if (++cnt == n - 1)
            break;
    }
}
int main() {
    int tot = 0, rub;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // if (i == j) {
            //     // scanf("%d ", &rub);
            //     getchar();
            //     continue;
            // }
            // e[++tot].x = i;
            // e[tot].y = j;
            // // scanf("%d ", &e[tot].v);
            // cin >> e[i].v;
            // if(e[i].v==0) cout << i << " " << j << endl;
            scanf("%d", &rub);
            if (j > i) {
                e[++tot].x = i;
                e[tot].y = j;
                e[tot].v = rub;
            }
        }
    }
    // cout << "input ok" << endl;
    kruskal();
    printf("%d", ans);
    return 0;
}