#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
int N, M, C;
struct edge {
    int to, w, nxt;
} g[maxn];
int tot, head[maxn];
void add(int u, int to, int w) {
    g[++tot].to = to;
    g[tot].w = w;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int ind[maxn], outd[maxn];  // in degree, out degree
int ans[maxn], bzy[maxn];   // the answer, Si
int main() {
    scanf("%d %d %d", &N, &M, &C);
    int n = N, m = C;
    for (int i = 1; i <= n; i++)
        scanf("%d", &ans[i]);
    for (int i = 1; i <= C; i++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        add(x, y, v);
        outd[x]++;
        ind[y]++;
    }

    queue<int> indz;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            indz.push(i);
            // ans[i] = 1;
        }
    }
    while (!indz.empty()) {
        int x = indz.front();
        indz.pop();
        for (int i = head[x]; i; i = g[i].nxt) {
            int y = g[i].to;
            ans[y] = max(ans[y], ans[x] + g[i].w);
            ind[y]--;
            if (ind[y] == 0)
                indz.push(y);
        }
    }

    for (int i = 1; i <= n; i++) {
        // if (ans[i] >= bzy[i])
            printf("%d\n", ans[i]);
        // else
            // printf("%d\n", bzy[i]);
    }
    return 0;
}