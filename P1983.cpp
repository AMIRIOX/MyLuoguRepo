#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n, m;
const int maxn = 1020;
const int maxm = 3e6+10;
struct edge {
    int to, nxt;
} g[maxm];
int tot, head[maxn];
void add(int u, int to) {
    g[++tot].to = to;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int ind[maxn], dep[maxn], ans;
void topological_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
            dep[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = g[i].nxt) {
            int v = g[i].to;
            dep[v] = dep[u] + 1;
            ans = max(ans, dep[v]);
            ind[v]--;
            if (!ind[v])
                q.push(v);
        }
    }
}
int nums, stopped[maxn], iss[maxn], built[maxn][maxn];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        memset(iss, 0, sizeof(iss));
        memset(stopped, 0, sizeof(stopped));
        scanf("%d", &nums);
        // needs: build a edge of the graph:
        // e: stopped->unstopped.
        for (int j = 1; j <= nums; j++) {
            scanf("%d", &stopped[j]);
            iss[stopped[j]] = 1;
        }
        for (int j = stopped[1] + 1; j <= stopped[nums]; j++) {
            if (!iss[j]) {
                // e: stopped->j
                for (int k = 1; k <= nums; k++)
                    // if (!built[stopped[k]][j]) {
                    //     ind[j]++;
                    //     add(stopped[i], j);
                    //     built[stopped[k]][j] = 1;
                    // }
                    if (!built[j][stopped[k]]) {
                        ind[stopped[k]]++;
                        add(j, stopped[k]);
                        built[j][stopped[k]] = 1;
                    }
            }
        }
    }
    topological_sort();
    printf("%d\n", ans);
    return 0;
}
