#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int fa[maxn], n, m, ans;

struct edge
{
    int u, v;
} e[maxn], ansv[maxn];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void unite(int a, int b)
{
    int ai = find(a);
    int bi = find(b);
    if (ai != bi)
        fa[ai] = bi;
}
void check(int u)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        if (i != u && find(e[i].u) != find(e[i].v))
            unite(e[i].u, e[i].v);
    for (int headx = find(1), i = 2; i <= n; i++)
        if (find(i) != headx)
        {
            ansv[++ans].u = min(e[u].u, e[u].v);
            ansv[ans].v = max(e[u].u, e[u].v);
            break;
        }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d %d", &e[i].u, &e[i].v);
    for (int i = 1; i <= m; i++)
        check(i);
    sort(ansv + 1, ansv + ans + 1, [&](edge &a, edge &b) {if(a.u==b.u) return a.v<b.v; else return a.u<b.u; });
    for (int i = 1; i <= ans; i++)
    {
        printf("%d %d\n", ansv[i].u, ansv[i].v);
    }
    return 0;
}