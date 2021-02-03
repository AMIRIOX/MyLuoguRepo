#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 5e4 + 10;
struct edge {
    int to, nxt;
} g[maxn];
int tot, head[maxn];
int n, m;
void add(int u, int to) {
    g[++tot].to = to;
    g[tot].nxt = head[u];
    head[u] = tot;
}
int took[maxn], maxdep;
int ind[maxn], dep[maxn];
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
        took[dep[u]]++;
        for (int i = head[u]; i; i = g[i].nxt) {
            int v = g[i].to;
            dep[v] = dep[u] + 1;
            maxdep = max(maxdep, dep[v]);
            ind[v]--;
            if (!ind[v])
                q.push(v);
        }
    }
}
int ans;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        add(x, y);
        ind[y]++;
    }
    topological_sort();
    for(int i=1;i<=maxdep;i++) {
        cout << took[i] << endl;
    }
    int mid = 0;
    for (int i = maxdep; i >= 1; i--) {
        if (took[dep[i]] == 1) {
            ans++;
        } else {
            mid = i;
            break;
        }
    }
    cout << mid << endl;
    if (!mid)
        for (int i = 1; i <= mid; i++) {
            if (took[dep[i]] == 1) {
                ans++;
            } else {
                break;
            }
        }
    printf("%d\n", ans);
    return 0;
}