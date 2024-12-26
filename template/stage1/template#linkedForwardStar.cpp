#include <cstdio>
#include <iostream>
#include <cstring>
// #define int long long
// #define INF 9223372036854775800LL
using namespace std;
const int maxn = 8e6 + 10;

struct edge {
    int to, w, nxt;
    edge() { nxt = -1; }
} Graph[maxn];
int tot, head[maxn];
void addEdge(int u, int to, int w) {
	tot++;
    Graph[tot].to = to;
    Graph[tot].w = w;
    Graph[tot].nxt = head[u];
    head[u] = tot;
}
signed main() {
    int n, m, flg; //有向/无向
    // cin >> n >> m >> flg;
    scanf("%d %d %d", &n, &m, &flg);
    // memset(head,-1,sizeof head);
    for(int i=1; i <= n; i++) {
    	head[i]=-1;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        if (flg) {
            addEdge(x, y, v);
        } else {
            addEdge(x, y, v);
            addEdge(y, x, v);
        }
    }
    // cout << "input ok" << endl;
    for (int u = 1; u <= n; u++)
        for (int i = head[u]; ~i; i = Graph[i].nxt) {
            int v = Graph[i].to;
            int w = Graph[i].w;
            // cout << u << " " << v << " " << w << endl;
            printf("%d %d %d\n", u, v, w);
        }
    return 0;
}