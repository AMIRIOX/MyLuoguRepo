#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int ls[maxn], rs[maxn], dist[maxn];
int fas[maxn];
bool deleted[maxn];
struct node {
    int v, id;
    bool operator<(node& o) const { return v == o.v ? id < o.id : v < o.v; }
} v[maxn];
int findx(int x) {
    return x == fas[x] ? x : fas[x] = findx(fas[x]);
}
int merge(int x, int y) {
    if (!x || !y)
        return x | y;
    if (v[y] < v[x])
        swap(x, y);
    rs[x] = merge(rs[x], y);
    if (dist[rs[x]] > dist[ls[x]])
        swap(ls[x], rs[x]);
    dist[x] = dist[rs[x]] + 1;
    return x;
}
int main(void) {
    int n, m;
    dist[0] = -1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i].v);
        fas[i] = i;
        v[i].id = i;
    }
    while (m--) {
        int cmd, xi, yi;
        scanf("%d %d", &cmd, &xi);
        if (cmd == 1) {
            scanf("%d", &yi);
            if (deleted[xi] || deleted[yi])
                continue;
            xi = findx(xi), yi = findx(yi);
            fas[xi] = fas[yi] = merge(xi, yi);

        } else {
            if (deleted[xi]) {
                printf("-1\n");
                continue;
            }
            xi = findx(xi);
            printf("%d\n", v[xi].v);
            deleted[xi] = true;
            fas[ls[xi]] = fas[rs[xi]] = fas[xi] = merge(ls[xi], rs[xi]);
            ls[xi] = rs[xi] = dist[xi] = 0;
        }
    }

    return 0;
}